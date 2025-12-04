// constructicon-simple.h
#ifndef CONSTRUCTICON_SIMPLE_H
#define CONSTRUCTICON_SIMPLE_H

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include "json.hpp"

// global scope for enum classes used in both the Constructicon and Annotator

// parse_method refers to how the pattern should be parsed (annotators set this for new triggers):
// • FullAuto: searches and validates trigger every time; best if it always applies, like "because"
// • SemiAuto: searches for trigger but requires human validation; best if it typically applies, like "arises from"
// • Manual: does not search for trigger and must be manually selected; best for noisy triggers, like "for" or "to"
enum class ParseMethod { FullAuto, SemiAuto, Manual, Unknown };

// enums for degree and order of causal constructions

// causal degree refers to polarity applied to causal relationships: 
// facilitate enables or assists an outcome; inhibit disables or hinders an outcome
enum class CausalDegree { Facilitate, Inhibit, Unknown };

// causal order is for the order in which cause and effect appear in the text
// and can be used for directionality rules in the graph:
// • CE: cause -> effect
// • EC: effect -> cause 
enum class CausalOrder { CE, EC, Unknown };

// enums for record annotations
// status refers to the review status: candidate, verified, rejected, or unknown
enum class AnnotationStatus { Candidate, Verified, Rejected, Unknown };

// helper functions to convert enums to strings
inline std::string parseMethodToString(ParseMethod method) {
    switch (method) {
        case ParseMethod::FullAuto:
            return "FullAuto";
        case ParseMethod::SemiAuto:
            return "SemiAuto";
        case ParseMethod::Manual:
            return "Manual";
        default:
            return "Unknown";
    }
}

inline std::string annotationStatusToString(AnnotationStatus status) {
    switch (status) {
        case AnnotationStatus::Candidate:
            return "Candidate";
        case AnnotationStatus::Verified:
            return "Verified";
        case AnnotationStatus::Rejected:
            return "Rejected";
        default:
            return "Unknown";
    }
}

inline std::string causalDegreeToString(CausalDegree degree) {
    switch (degree) {
        case CausalDegree::Facilitate:
            return "Facilitate";
        case CausalDegree::Inhibit:
            return "Inhibit";
        default:
            return "Unknown";
    }
}

inline std::string causalOrderToString(CausalOrder order) {
    switch (order) {
        case CausalOrder::CE:
            return "CE";
        case CausalOrder::EC:
            return "EC";
        default:
            return "Unknown";
    }
}

// namespace for the reference set of causal constructions and associated resources
namespace CausalConstructicon {

    // structure for a single causal construction
    // this could be expanded with classifications of causal relationships such as disentail
    // it could also be generalized for other constructions like temporal constructions
    struct CausalConstruction {
        std::string id;
        CausalDegree degree;
        CausalOrder order;
        std::string trigger_template;
        std::string example;

        // default constructor
        CausalConstruction() : id(""), degree(CausalDegree::Unknown), order(CausalOrder::Unknown), trigger_template(""), example("")  {}

        // parameterized constructor with initialization list
        CausalConstruction(const std::string& i, CausalDegree d, CausalOrder o, const std::string& t, const std::string& e) : 
        id(i), degree(d), order(o), trigger_template(t), example(e) {}
    };

    // pattern for mapping regex string patterns to construction IDs
    struct CausalPattern {
        // corresponds to trigger_template in the construction
        std::string description;
        // compiled regex
        std::regex  pattern;           
        // one or more construction IDs (e.g., {"C001"})      
        std::vector<std::string> ids;        
        // parse method; can be set during annotation process
        ParseMethod parse_method;  

        // default constructor
        CausalPattern() : description(""), pattern(std::regex("")), ids({}), parse_method(ParseMethod::Unknown) {}
        
        // parameterized constructor
        CausalPattern(const std::string& d, const std::regex& p, const std::vector<std::string>& i, ParseMethod m = ParseMethod::Unknown) :
        description(d), pattern(p), ids(i), parse_method(m) {}
    };

    //  storage vector declarations
    extern std::vector<CausalConstruction> constructions;
    extern std::vector<CausalPattern> patterns;

    // accessors for constructions and patterns
    std::vector<CausalConstruction>& getConstructions(); 
    std::vector<CausalPattern>& getPatterns();

    // functions to add new constructions and patterns
    void addConstruction(const CausalConstruction& construction);
    void addPattern(const CausalPattern& pattern);

    // find helper function declarations
    const CausalConstruction* findConstructionByID(const std::string& id);

    struct ConstructiconInitializer;

    // initialize constructions and patterns
    extern ConstructiconInitializer constructiconInitializer;
}

// namespace for record processing and annotation workflow
namespace Annotator {
    using json = nlohmann::json;

    // unannotated record consisting of a key (in this case, the NTSB record ID) and probable cause statement
    struct Record {
        int recordID;
        std::string probableCause;

        // default constructor
        Record() : recordID(0), probableCause("") {}

        // parameterized constructor with initialization list
        Record(int r, const std::string& p) : 
        recordID(r), probableCause(p) {}
    };

    // helper functions for annotation process
    // get user input for text span
    std::string getTextSpan(const std::string& prompt, const std::string& fullText);
    
    // show the record
    void displayRecord(const Record& record);

    // save the current index for progress tracking 
    void saveCurrentIndex(size_t index);

    // load the last saved index for prgress tracking
    size_t loadLastIndex();

    // option to continue or exit after annotating each record
    bool optionToContinue();

    // save after annotating each record
    void saveAnnotations();

    // annotation entry with causal construction ID, record ID, trigger, cause, effect, status, and parse method
    // may be expanded to include token start and end indices for trigger, cause, and effect
    struct AnnotationEntry {
        std::string constructionID;
        int recordID;
        std::string trigger;
        std::string cause;
        std::string effect;
        AnnotationStatus status;
        ParseMethod parse_method;
        
        // default constructor
        AnnotationEntry() : constructionID(""), recordID(0), status(AnnotationStatus::Unknown), parse_method(ParseMethod::Unknown) {}

        // parameterized constructor with initialization list
        AnnotationEntry(const std::string& cid,
            int r,
            const std::string& t,
            const std::string& ca,
            const std::string& e,
            AnnotationStatus s = AnnotationStatus::Unknown,
            ParseMethod m = ParseMethod::Unknown)
            : constructionID(cid), recordID(r), trigger(t), cause(ca), effect(e), status(s), parse_method(m)
        {}
    };

    //  storage vector declarations
    extern std::vector<Record> records;
    extern std::vector<AnnotationEntry> annotations;

    std::vector<AnnotationEntry>& getAnnotations();
    void addAnnotationEntry(const AnnotationEntry& entry);

    struct AnnotatorInitializer;

    extern AnnotatorInitializer annotatorInitializer;

    // current record being annotated
    extern const Record* currentRecord;
    extern size_t currentRecordIndex;
    
    // initialize annotation process
    void startAnnotationProcess();
    
    // manual entry option after automatic processing
    void manualEntry(const Record& record, bool automaticProcessingDone);

    // process one record
    bool processRecord(size_t recordIndex);
    
    // highlight the trigger in different colors based on the status
    // green: Verified
    // yellow: Candidate
    // red: Rejected
    void displayTextWithHighlight(const std::string& trigger, AnnotationStatus status);

    // find all pattern matches in current record
    std::vector<AnnotationEntry> findPatternMatches(const Record& record);
    
    // process a single match (user interaction)
    AnnotationEntry processMatch(const CausalConstructicon::CausalPattern& pattern, 
        const std::string& trigger,
        const Record& record);
}

#endif // CONSTRUCTICON_SIMPLE_H