#include "constructicon-simple.h"
#include "constructions.h"
#include "patterns.h"
#include <iostream>
#include <fstream>

namespace CausalConstructicon {

    // storage
    std::vector<CausalConstruction> constructions;
    std::vector<CausalPattern> patterns;

    // constructions
    std::vector<CausalConstruction>& getConstructions() {
        return constructions;
    }

    void addConstruction(const CausalConstruction& construction) {
        if (findConstructionByID(construction.id) == nullptr) {
            constructions.push_back(construction);
        } else {
            std::cerr << "Warning: Construction with ID " << construction.id << " already exists. Skipping." << std::endl;
        }
    }

    const CausalConstruction* findConstructionByID(const std::string& id) {
        for (auto& construction : constructions) {
            if (construction.id == id) {
                return &construction;
            }
        }
        return nullptr;
    }

    // patterns
    void addPattern(const CausalPattern& newPattern) {
        for (const auto& pattern : patterns) {
            if (pattern.description == newPattern.description) {
                std::cerr << "Warning: Pattern '" << pattern.description << "' already exists. Skipping." << std::endl;
                return;
            }
        }
        patterns.push_back(newPattern);
    }

    std::vector<CausalPattern>& getPatterns() {
        return patterns;
    }

    // initialize constructions and patterns
    struct ConstructiconInitializer {
        ConstructiconInitializer() {
            // load all constructions
            for (const auto& c : InitialConstructions::constructions) {
                addConstruction(c);
            }
            // load all patterns
            for (const auto& p : InitialPatterns::patterns) {
                addPattern(p);
            }
            std::cout << "Constructicon initialized: " 
            << constructions.size() << " constructions, "
            << patterns.size() << " patterns" << std::endl;
        }
    };

    // static instance to run initialization at program start
    ConstructiconInitializer constructiconInitializer;
}

namespace Annotator {
    std::vector<Record> records;
    std::vector<AnnotationEntry> annotations;

    std::vector<AnnotationEntry>& getAnnotations() {
        return annotations;
        }

    void addAnnotationEntry(const AnnotationEntry& entry) { 
        annotations.push_back(entry); 
        }

    struct AnnotatorInitializer {
        AnnotatorInitializer() {
            std::cout << "Loading NTSB accident records..." << std::endl;
            
            try {
                std::ifstream file("cleaned_data.json");
                json data = json::parse(file);
                
                records.reserve(data.size());
                
                for (const auto& item : data) {
                    records.emplace_back(
                        item["cm_mkey"].get<int>(),
                        item["cm_probableCause"].get<std::string>()
                    );
                }
                
                std::cout << "Annotator initialized: " 
                          << records.size() << " records" << std::endl;
                          
            } catch (...) {
                std::cerr << "Failed to load records from cleaned_data.json" << std::endl;
            }
        }
    };
    
    // initialize annotator
    AnnotatorInitializer annotatorInitializer;
        const Record* currentRecord = nullptr;
    size_t currentRecordIndex = 0;
    
    // save the current index for progress tracking 
    void saveCurrentIndex(size_t index) {
        std::ofstream file("progress.txt");
        if (file.is_open()) {
            file << index;
            file.close();
        }
    }

    // load the last saved index for progress tracking
    size_t loadLastIndex() {
        std::ifstream file("progress.txt");
        if (!file.is_open()) {
            return 0;
        }
        
        size_t index;
        file >> index;
        return index;
    }

    // start annotation from first record
    void startAnnotationProcess() {
        if (records.empty()) {
            std::cout << "No records to annotate." << std::endl;
            return;
        }
        
        std::cout << "\nStarting annotation process\n" << std::endl;
     
        // load last saved index
        size_t startIndex = loadLastIndex();
        if (startIndex > 0) {
            std::cout << "Resuming from record " << (startIndex + 1) << std::endl;
        }

        for (size_t i = startIndex; i < records.size(); i++) {

            // process one record
            processRecord(i);                   
            
            // always save after processing each record
            saveAnnotations();
            
            // ask if user wants to continue after each record
            bool continueToNext = optionToContinue();
            
            // if user decides to stop, track progress, and exit the program
            if (!continueToNext) {

                // save current index to track progress
                saveCurrentIndex(i + 1);
                std::cout << "\nEnd of session. All annotation entries saved to annotations.csv." << std::endl;
                return;
            }

            // if continuing, save current index to track progress
            saveCurrentIndex(i + 1);
        }

        // if we get here, all records were processed
        std::cout << "\nAll records processed!" << std::endl;
        saveAnnotations();
        }
    
    // process one record
    bool processRecord(size_t recordIndex) {
        if (recordIndex >= records.size()) return false;
        
        currentRecordIndex = recordIndex;
        currentRecord = &records[recordIndex];
        
        std::cout << "\n~~~ Processing record " << (recordIndex + 1) 
                << " of " << records.size() << " ~~~" << std::endl;
        std::cout << "Record ID: " << currentRecord->recordID << "\n" << std::endl;
        
        // show full record
        displayRecord(*currentRecord);
        
        // track if any automatic processing was done
        bool automaticProcessingDone = false;

        // automatic processing: find all pattern matches in record
        auto matches = findPatternMatches(*currentRecord);  
        
        automaticProcessingDone = true;
        
        // option to add manual annotation entry after automatic processing
        manualEntry(*currentRecord, automaticProcessingDone);

        return true; // continue to next record
    }
    
    // helper: get text span from user for cause and effect
    std::string getTextSpan(const std::string& prompt, const std::string& fullText) {
        std::string span;
        std::cout << prompt;
        std::getline(std::cin, span);
        return span;
    }
    
    // helper: display full record with simple formatting
    // TODO: add text wrapping
    void displayRecord(const Record& record) {
        std::cout << "Accident report: " << std::endl;
        std::cout << record.probableCause << std::endl;
    }

    // helper: display text with highlighted trigger based on status
    void displayTextWithHighlight(const std::string& trigger, AnnotationStatus status) {
        if (!currentRecord) return;
    
        std::string text = currentRecord->probableCause;
        size_t pos = text.find(trigger);
        if (pos == std::string::npos) return;
        
        // choose color based on status
        // these are ANSI escape codes
        std::string color;
        switch(status) {
            case AnnotationStatus::Candidate:
                color = "\033[33m"; // yellow
                break;
            case AnnotationStatus::Verified:
                color = "\033[32m"; // green
                break;
            case AnnotationStatus::Rejected:
                color = "\033[31m"; // red
                break;
            default:
                color = "\033[0m"; // reset
                break;
        }
        
        std::cout << text.substr(0, pos)
                << color << trigger << "\033[0m"
                << text.substr(pos + trigger.length()) << std::endl;
    }

    // automatic processing: find pattern matches in record 
    // TODO: search for longest matches first, then substrings, e.g. "the probable cause of" then "cause"
    std::vector<AnnotationEntry> findPatternMatches(const Record& record) {
    std::vector<AnnotationEntry> matches;
    const auto& patterns = CausalConstructicon::getPatterns();
    
    for (const auto& pattern : patterns) {
        std::string text = record.probableCause;
        std::smatch regexMatch;
        
        // search for pattern
        if (std::regex_search(text, regexMatch, pattern.pattern)) {
            // found a match
            std::string trigger = regexMatch.str();
            
            std::cout << "\n~~~ Automatic Matching Phase ~~~" << std::endl;
            std::cout << "\nMatching pattern: " << pattern.description << std::endl;
            std::cout << "Causal connector: \"" << trigger << "\"" << std::endl;
            
            // show candidate in yellow
            std::cout << "\nFull record (candidate trigger highlighted):" << std::endl;
            displayTextWithHighlight(trigger, AnnotationStatus::Candidate);
            
            // ask user if valid
            std::cout << "\nIs this a valid causal connector? (y/n): ";
            std::string response;
            std::getline(std::cin, response);
                       
            if (response == "y" || response == "yes" || response == "Y") {
                // user said yes: set status to Verified, and show text in green
                // TODO: the text should remain green or red as long as the same record is in focus
                std::cout << "\nVerified:" << std::endl;
                
                // create annotation entry
                AnnotationEntry entry;
                
                // a trigger may evoke multiple construction IDs, but for now we assume the ID in the first index of ids
                // TODO: if multiple constructions are evoked, prompt the user to select the right one
                entry.constructionID = pattern.ids.empty() ? "" : pattern.ids[0];
                entry.recordID = record.recordID;
                entry.trigger = trigger;
                entry.status = AnnotationStatus::Verified;

                displayTextWithHighlight(trigger, entry.status);
                std::cout << "\nCausal connector verified." << std::endl;

                // get cause and effect spans from user
                std::cout << "\nPlease identify the CAUSE span (copy/paste from text):" << std::endl;
                entry.cause = getTextSpan("Cause: ", text);
                
                std::cout << "\nPlease identify the EFFECT span (copy/paste from text):" << std::endl;
                entry.effect = getTextSpan("Effect: ", text);

                // add to annotations
                addAnnotationEntry(entry);

                // show saved confirmation
                std::cout << "\nAnnotation saved." << std::endl;
                std::cout << "Record ID: " << entry.recordID << std::endl;
                std::cout << "Construction ID: " << entry.constructionID << std::endl;
                std::cout << "Causal connector: " << entry.trigger << std::endl;
                std::cout << "Cause: " << entry.cause << std::endl;       
                std::cout << "Effect: " << entry.effect << std::endl;
                
                matches.push_back(entry);
            
            // storing rejected entries can be useful for testing precision and recall
            // as an option, rejected entries do not need to be stored
            // TODO: when generating the graph, make sure to ignore rejected annotation entries
            } else {
                // user said no: set status to Rejected, and show text in red
                std::cout << "\nRejected:" << std::endl;
                
                AnnotationEntry rejected;
                rejected.constructionID = pattern.ids.empty() ? "" : pattern.ids[0];
                rejected.recordID = record.recordID;
                rejected.trigger = trigger;
                rejected.status = AnnotationStatus::Rejected;
                addAnnotationEntry(rejected);

                displayTextWithHighlight(trigger, rejected.status);
                std::cout << "\nCausal connector rejected." << std::endl;
            }
        }
    }
    
    return matches;
    }

    // option to add manual annotation entries
    void manualEntry(const Record& record, bool automaticProcessingDone) {
        if (!automaticProcessingDone)
            return;
        
        std::cout << "\n~~~ Manual Annotation Phase ~~~" << std::endl;

        // show the full record again for manual annotation
        displayRecord(record);

        std::cout <<"\nAre there any remaining causal connectors in this text? (y/n)" << std::endl;
        std::string response;
        std::getline(std::cin, response);

        // terminating condition for recursion: if not "y" or "yes" or "Yes" or "Y", end recursion
        if (response != "y" && response != "yes" && response != "Yes" && response != "Y") {
            std::cout << "Moving on to the next record.\n" << std::endl;
            return; 
        }
    
        // create new annotation entry with status Verified
        AnnotationEntry entry;
        entry.status = AnnotationStatus::Verified;
        
        // temporary ID for manual entries
        // TODO: in postprocessing step, generate unique construction IDs for all manual entries (TK: "to come")
        entry.constructionID = "TK";  
        entry.recordID = record.recordID;

        // get the trigger, cause, and effect spans from the user
        std::cout << "Please copy and paste the causal connector text here." << std::endl;
        std::cout << "Causal connector: ";
        std::getline(std::cin, entry.trigger);

        // show trigger in green
        std::cout << "\nVerified causal connector highlighted in green:" << std::endl;
        displayTextWithHighlight(entry.trigger, entry.status);

        std::cout << "\nPlease identify the CAUSE span (copy/paste from text):" << std::endl;
        entry.cause = getTextSpan("Cause: ", record.probableCause);

        std::cout << "\nPlease identify the EFFECT span (copy/paste from text):" << std::endl;
        entry.effect = getTextSpan("Effect: ", record.probableCause);

        // prompt the user to set the parsing method for the trigger in future pattern searches
        std::cout << "\nPlease select the parsing method for this causal connector pattern:" << std::endl;
        std::cout << "A: FullAuto (always applies, e.g., 'because')" << std::endl;
        std::cout << "B: SemiAuto (typically applies, e.g., 'arises from')" << std::endl;
        std::cout << "C: Manual (noisy triggers, e.g., 'for' or 'to')" << std::endl;
        std::cout << "Enter A, B, or C: ";
        
        std::string parseMethodChoice;
        ParseMethod parseMethod = ParseMethod::Unknown;
        
        while (parseMethod == ParseMethod::Unknown) {
            std::getline(std::cin, parseMethodChoice);
            
            if (parseMethodChoice == "A" || parseMethodChoice == "a") {
                parseMethod = ParseMethod::FullAuto;
            } else if (parseMethodChoice == "B" || parseMethodChoice == "b") {
                parseMethod = ParseMethod::SemiAuto;
            } else if (parseMethodChoice == "C" || parseMethodChoice == "c") {
                parseMethod = ParseMethod::Manual;
            } else {
                std::cout << "Invalid choice. Please enter A, B, or C: ";
            }
        }

        entry.parse_method = parseMethod; 
               
        // add to annotations
        addAnnotationEntry(entry);
        std::cout << "\nManual annotation saved." << std::endl;
        std::cout << "Record ID: " << entry.recordID << std::endl;
        std::cout << "Construction ID: " << entry.constructionID << std::endl;
        std::cout << "Causal connector: " << entry.trigger << std::endl;
        std::cout << "Cause: " << entry.cause << std::endl;       
        std::cout << "Effect: " << entry.effect << std::endl;
        
        // recursive call to add another manual annotation
        manualEntry(record, automaticProcessingDone);         
    }

    // option to continue to next record, in which case it saves and continues
    // continues if it returns true; else it returns false and then saves
    bool optionToContinue() {
        std::cout << "\nSave and continue to next record? (y/n). \nAny other input will save and exit the program.";
        std::string choice;
        std::getline(std::cin, choice);

        return (choice == "y" || choice == "yes" || choice == "Yes" || choice == "Y");
    }

    // save to csv file for further processing into graph
    // filter only saves verified annotations
    // opens in append mode
    void saveAnnotations() {
        std::ofstream file("annotations.csv", std::ios::app);
        
        // write header only if file is empty
        if (file.tellp() == 0) {
        file << "construction_id,record_id,trigger,cause,effect,status\n";
    }
        int verifiedCount = 0;
        
        for (const auto& entry : annotations) {
            if (entry.status == AnnotationStatus::Verified) {
                file << entry.constructionID << ","
                    << entry.recordID << ","
                    << "\"" << entry.trigger << "\","
                    << "\"" << entry.cause << "\","
                    << "\"" << entry.effect << "\","
                    << "Verified"
                    << "\n";
                verifiedCount++;
            }
        }
        
        file.close();

        std::cout << verifiedCount << " total verified annotations saved to annotations so far.csv\n";
    }
}