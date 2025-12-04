# Causal Constructicon and Annotation System

A tool for extracting causal relationships from using linguistic patterns and semi-automated annotation. 

Text example: NTSB accident reports.

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
- `constructions.h` - 152 causal constructions (e.g., "C001: <cause> where <effect>"):
```cpp
{
    "C010",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect>, as <cause>",
    "As science has yet to prove or disprove the existence of a divine power, and probably never will, I will use my gift of reason.  As the power increased, the rotor spun faster."
},
```
- `patterns.h` - 96 regex patterns for matching:
```cpp
{
    "<cause> gives rise to <effect>",
    std::regex(R"(\b(give|gives|gave|given|giving)\s+rise\s+to\b)", std::regex::icase),
    {"C017"}
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

## Annotation Process
1. **Pattern matching** - System finds potential causal connectors using regex patterns
2. **User validation** - Review each match, label cause/effect spans
3. **Manual entry** - Add connectors missed by automatic matching
4. **Progress tracking** - Resume where you left off using `progress.txt`

## Parsing Automation Methods

Choose one of three parsing methods when annotating causal connectors:

| Type | When to Use | Example |
|------|-------------|---------|
| **FullAuto** | The trigger always indicates causality | "because", "resulting in" |
| **SemiAuto** | The trigger typically indicates causality | "arises from", "promotes" |
| **Manual** | The trigger is noisy/ambiguous | "for", "from", "when" |

## Output Files
- `annotations.csv` - Verified causal relationships (construction_id, record_id, trigger, cause, effect)
```csv
construction_id,record_id,trigger,cause,effect,status
C148,193383,"contributed to","pilot error","accident",Verified
TK,193384,"led to","mechanical failure","crash",Verified
```

- `causal_links.ttl` - RDF knowledge graph in Turtle format (generated via `csv_to_rdf.py`)
```turtle
[] a ex:Causation ;
    ex:cause "The failure of the alternate gear extension system" ;
    ex:connector "prevented" ;
    ex:effect "the landing gear from being lowered" ;
    ex:constructionID "C039" ;
    ex:recordID "193196" .
```

## Generating RDF Graphs from CSV
After annotating records, convert your `annotations.csv` to an RDF knowledge graph:
```bash
# run the converter
python csv_to_rdf.py
```
This generates `causal_links.ttl` containing:

- Reified causation statements (cause → effect relationships)
- Causal connectors used
- Construction IDs and record IDs for traceability
- Turtle format RDF

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
└── README.md                       # This documentation file
```

## Features
- Three pattern identification modes: full auto, semi auto, manual
- Progress tracking so that progress can continue over multiple sessions
- Color-coded highlighting for validation
- CSV export to prepare for graph generation
- RDF knowledge graph generation

## Data Flow
```
NTSB Reports → Pattern Matching → User Validation → CSV Output → RDF Knowledge Graph
```

## System Architecture
Complete workflow from raw data through annotation to RDF knowledge graph generation:

![Causal Annotation System Diagram](https://raw.githubusercontent.com/falcontologist/cu-cspb2270-2025-final_project/main/system_diagram_dark.png)
