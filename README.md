# Causal Constructicon and Annotation System

A semi-automated annotation system for high-precision extraction and graph generation of causal relationships using form-meaning pairings.


## What is the Causal Constructicon?

Based on the theory of Construction Grammar, a **Constructicon** is a comprehensive lexicon of constructions that a speaker learns, remembers, and uses to generate and understand language. Every construction in this inventory is a conventionally learned pairing of a surface **form** and an associated **meaning**. In this case, we are focusing on the set of constructions that relate **causes** and **effects** in natural language. 


## What is the Annotation System?

The primary goal of this project is to develop a high-precision, deterministic, annotation system to identify and extract these causal constructions from text with a human in the loop. A manual annotation option allows users to pinpoint causal links that might have been missed and add new constructions to the inventory. The resulting annotations can then be transformed into a graph, or used as training data for machine learning pipelines. As a case study, we are using accident reports from the National Transportation Safety Bureau, as they are rich with causal links.


## Prerequisites

C++ Dependencies:

- C++17 Compiler: Use a compatible compiler (e.g., g++ 7+ or clang 5+).
- JSON Header: Make sure that you have the json.hpp in the project directory.

Python Dependencies:

- Install the required Python packages for the CSV to RDF graph generator:

```bash
pip install pandas rdflib
```


## Quick Start

```bash
# compile the constructicon and annotator
g++ -std=c++17 -o annotator constructicon-simple.cpp

# run the annotator
./annotator
```


## Initialization

The system automatically initializes when you compile and run the program:

1. **Constructicon Initialization**: Loads all causal constructions and regex patterns from `constructions.h` and `patterns.h`
2. **Annotator Initialization**: Loads accident records from `cleaned_data.json`
3. **Static Initializers**: The `ConstructiconInitializer` and `AnnotatorInitializer` objects run automatically at program start


## Input Files
- `cleaned_data.json` - sample text from [NTSB accident reports](https://carol.ntsb.gov):
```json
[
  {
    "cm_mkey": 12345,
    "cm_probableCause": "The pilot failed to maintain altitude..."
  }
]
```
- `constructions.h` - 152 causal constructions:
```cpp
{
    "C010",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect>, as <cause>",
    "As science has yet to prove or disprove the existence of a divine power, and probably never will, I will use my gift of reason.  As the power increased, the rotor spun faster."
},
```
- `patterns.h` - 96 regex patterns for matching (omitting noisy triggers):
```cpp
{
    "<cause> gives rise to <effect>",
    std::regex(R"(\b(give|gives|gave|given|giving)\s+rise\s+to\b)", std::regex::icase),
    {"C017"},
    ParseMethod::SemiAuto
},
```


## Checking Data Loading and Progress
The `minimal_checker` utility shows what data has been loaded and the number of records processed so far:
```bash
# compile the checker
g++ -std=c++17 -o minimal_checker minimal_checker.cpp constructicon-simple.cpp

# run the checker
./minimal_checker
```


## Data Structures

1. CausalConstruction
```cpp
struct CausalConstruction {
    std::string id;                // unique ID for a construction, e.g. "C001", "C146"
    CausalDegree degree;           // Facilitate or Inhibit, depending on polarity
    CausalOrder order;             // CE (cause -> effect) or EC (effect -> cause)
    std::string trigger_template;  // trigger in context of the construction
    std::string example;           // example of the construction in context
};
```

2. CausalPattern
```cpp
struct CausalPattern {
    std::string description;       // human-readable description of the construction in context
    std::regex pattern;            // regular expression, e.g. std::regex(R"(\bis\s+why\b)", std::regex::icase)
    std::vector<std::string> ids;  // one or multiple Construction IDs, e.g. {"C146"}
    ParseMethod parse_method;      // parse method used for pattern matching: FullAuto, SemiAuto, or Manual
};
```
3. Record
```cpp
struct Record {
    int recordID;                  // NTSB accident record ID, e.g. 193383
    std::string probableCause;     // NTSB probable cause statement following an investigation.
};
```
4. AnnotationEntry
```cpp
struct AnnotationEntry {
    std::string constructionID;    // Construction ID, e.g. "C146"
    int recordID;                  // Record ID, e.g. 193383
    std::string trigger;           // word, phrase, or pattern that evokes a construction, e.g. "due to"
    std::string cause;             // span of text that encompasses the cause associated with the connector
    std::string effect;            // span of text that encompasses the effect associated with the connector
    AnnotationStatus status;       // verification status: Verified, Candidate, Rejected, or Unknown
    ParseMethod parse_method;      // annotator sets the parse method: FullAuto, SemiAuto, or Manual
};
```   

These structures are all contained in vectors:

```cpp
std::initializer_list<CausalConstruction> constructions

std::initializer_list<CausalPattern> patterns

std::vector<Record> records

std::vector<AnnotationEntry> annotations
```


## Annotation Process
1. **Pattern matching** - System finds potential causal connectors using regex patterns
2. **User validation** - Review each match, label cause/effect spans
3. **Manual entry** - Add connectors missed by automatic matching
4. **Progress tracking** - Resume where you left off using `progress.txt`


## Terminal Colors

During annotation in the terminal, triggers are highlighted with ANSI escape colors:

- 🔴 Red (Rejected): User-rejected match
- 🟡 Yellow (Candidate): Potential match found by pattern search
- 🟢 Green (Verified): Confirmed causal connector

When a match is found, it is highlighted in yellow to show that it is a candidate. If the user confirms that it is valid, it changes to green. If the user rejects it, it turns to red. These colors help visually track progress while working in one record.


## Parsing Automation Methods

Choose one of three parsing methods when annotating causal connectors:

| Type      | What it does                                      | When to Use                             | Example                       |
|-----------|----------------------------------------------------|-------------------------------------------|-------------------------------|
| **FullAuto** | Automatically validates trigger as causal connector | Trigger always indicates causality     | "because", "resulting in"     |
| **SemiAuto** | Automatically flags candidate, prompts validation | Trigger typically indicates causality | "arises from", "promotes"     |
| **Manual**   | Never searches for trigger, requires manual entry | Trigger is noisy or polysemous        | "for", "from", "when"         |

These parse methods can be set during the manual annotation phase only. In future versions, these settings will be incorporated into the pattern structs and applied during the pattern matching process.


## Output Files
- `annotations.csv` - Verified causal relationships (construction_id, record_id, trigger, cause, effect)
```csv
construction_id,record_id,trigger,cause,effect,status
C148,193383,"contributed to","pilot error","accident",Verified
TK,193384,"led to","mechanical failure","crash",Verified
```

- `causal_links.ttl` - RDF knowledge graph in Turtle format (generated via `csv_to_rdf.py`)
```turtle
[] a :Causation ;
    :cause "The failure of the alternate gear extension system" ;
    :connector "prevented" ;
    :effect "the landing gear from being lowered" ;
    :constructionID "C039" ;
    :recordID "193196" .
```


## Generating RDF Graphs from CSV
After annotating records, convert your `annotations.csv` to an RDF knowledge graph:
```bash
# run the converter
python csv_to_rdf.py
```
This generates a Turtle file `causal_links.ttl` containing:

- Reified causation statements (cause → effect relationships)
- Causal connectors used
- Construction IDs and record IDs for traceability


## Project Structure
```
├── constructicon-simple.h/.cpp     # Core library & annotation logic
├── constructions.h                 # 152 causal construction definitions
├── patterns.h                      # 96 regex patterns for matching
├── json.hpp                        # JSON parsing library (nlohmann)
├── cleaned_data.json               # NTSB accident reports (input)
├── annotations.csv                 # Verified causal relationships (output)
├── progress.txt                    # Session progress tracking
├── causal_links.ttl                # RDF knowledge graph (example generated output)
├── system_diagram_dark.png         # System workflow diagram (dark theme)
├── csv_to_rdf.py                   # CSV → RDF converter
├── minimal_checker.cpp             # Data loading verification utility
├── tests.cpp                       # Unit tests for core functionality
├── graphviz_example.dot            # Dot format graph visualization of causal chain
├── graphviz_example.png            # GraphViz visualization of causal chain sequence
└── README.md                       # This documentation file
```


## Features at a Glance
- Shallow semantic parsing based on construction grammar
- Expedites and enhances human annotation tasks
- Three pattern identification modes: full auto, semi auto, manual
- Progress tracking so that progress can continue over multiple sessions
- Color-coded highlighting for validation
- Annotations can be used as gold training data for machine learning
- CSV export to prepare for graph generation
- RDF knowledge graph generation


## Data Flow
```
NTSB Reports → Pattern Matching → User Validation → CSV Output → RDF Knowledge Graph
```

## System Architecture
Complete workflow from raw data through annotation to RDF knowledge graph generation:

![Causal Annotation System Diagram](https://raw.githubusercontent.com/falcontologist/cu-cspb2270-2025-final_project/main/system_diagram_dark.png)

## Example Graph Visualization
Here is an example of a causal chain extracted from the annotation process, converted into an RDF graph, and visualized in GraphViz.

![Example Causation Graph Diagram](https://github.com/falcontologist/cu-cspb2270-2025-final_project/blob/main/graphviz_example.png)


## References

Allen, J. F. (1983). *Maintaining knowledge about temporal intervals*. **Communications of the ACM, 26**(11), 832–843.

Cowan, R. (2008). *The teacher’s grammar of English*. Cambridge University Press.

Croft, W., Kalm, P., & Regan, M. (2022). *Decomposing events and storylines*. In **Decompositional event structures in language, cognition, and computation** (pp. 67–86). Cambridge University Press.

Croft, W., Pešková, P., & Regan, M. (2017). *Integrating decompositional event structure into storylines*. In T. Caselli, B. Miller, M. van Erp, & others (Eds.), **Proceedings of the Workshop on Events and Stories in the News** (pp. 98–109). Association for Computational Linguistics.

Dixon, R. (Ed.). (2006). *Complementation: A cross-linguistic typology*. Oxford University Press.

Dixon, R., & Aikhenvald, A. (Eds.). (2009). *The semantics of clause linking: A cross-linguistic typology*. Oxford University Press.

Dunietz, J. (2018). *Annotating and automatically tagging constructions of causal language* (Doctoral dissertation). Carnegie Mellon University, Pittsburgh, PA.

Dunietz, J. (n.d.). *GitHub profile*. Retrieved from https://github.com/duncanka

Dunietz, J. (n.d.). *BECAUSE: The BECauSE Corpus and tools*. GitHub repository. Retrieved from https://github.com/duncanka/BECAUSE

Dunietz, J. (n.d.). *Causeway: A causality annotation and analysis toolkit*. GitHub repository. Retrieved from https://github.com/duncanka/Causeway

Dunietz, J. (n.d.). *LSTM Causality Tagger*. GitHub repository. Retrieved from https://github.com/duncanka/lstm-causality-tagger

Dunietz, J., Levin, L., & Carbonell, J. (2017). *The BECauSE Corpus 2.0: Annotating causality and overlapping relations*. In **LAW XI – The 11th Linguistic Annotation Workshop**.

Dunietz, J., Levin, L., & Carbonell, J. (2018). *DeepCx: A transition-based approach for shallow semantic parsing with complex constructional triggers*. In **Proceedings of EMNLP 2018**.

Goldberg, A. E. (1995). *Constructions: A construction grammar approach to argument structure*. University of Chicago Press.

Gordon, A., & Hobbs, J. (2017). *A formal theory of commonsense psychology: How people think people think*. Cambridge University Press.

Matthiessen, C., & Thompson, S. (1988). *The structure of discourse and “subordination.”* In M. Haiman & S. Thompson (Eds.), **Clause combining in grammar and discourse** (pp. 275–329). John Benjamins Publishing.

National Transportation Safety Board. (n.d.). *NTSB accident reports*. Retrieved from https://carol.ntsb.gov

Rezvani Kalajahi, S., Abdullah, A., Mukundan, J., & Tannacito, D. (2012). *Discourse connectors: An overview of the history, definition and classification of the term*. **World Applied Sciences Journal, 19**(11), 1659–1673.

Rezvani Kalajahi, S., Neufeld, S., & Abdullah, A. (2017). *The discourse connector list: A multi-genre cross-cultural corpus analysis*. **Text & Talk, 37**(3), 283–310.

Talmy, L. (1988). *Force dynamics in language and cognition*. **Cognitive Science, 12**(1), 49–100.

Talmy, L. (2000). *Toward a cognitive semantics, Volume 1: Concept structuring systems*. MIT Press.


## Acknowledgments

This project incorporates data derived from publicly available National Transportation Safety Board (NTSB) accident reports.  
It also builds on the comprehensive research program on causal constructions developed by Jesse Dunietz. Many of the reference constructions in `constructions.h` are adapted from Appendix C of his 2018 dissertation. His linked repositories, released under the MIT License, informed the methodology used here.
