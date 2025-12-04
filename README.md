# Causal Constructicon and Annotation System

A tool for extracting causal relationships from using linguistic patterns and semi-automated annotation. Text example: NTSB accident reports.

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
# Compile
g++ -std=c++17 -o annotator constructicon-simple.cpp minimal_checker.cpp

# Run annotation tool
./annotator
```

## Input Files
- `cleaned_data.json` - NTSB accident reports (required)
- `constructions.h` - 152 causal constructions (e.g., "C001: <cause> where <effect>")
- `patterns.h` - 96 regex patterns for matching

## Annotation Process
1. **Automatic matching** - System finds potential causal connectors using regex patterns
2. **User validation** - Review each match, label cause/effect spans
3. **Manual entry** - Add connectors missed by automatic matching
4. **Progress tracking** - Resume where you left off using `progress.txt`

## Output Files
- `annotations.csv` - Verified causal relationships (construction_id, record_id, trigger, cause, effect)
- `causal_links.ttl` - RDF knowledge graph (generated via `csv_to_rdf.py`)

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
