# Causal Annotation System

A tool for extracting causal relationships from using linguistic patterns and semi-automated annotation. Text example: NTSB accident reports.

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
├── constructicon-simple.h/.cpp    # Core library & annotation logic
├── constructions.h                # Causal construction definitions
├── patterns.h                     # Regex patterns for matching
├── minimal_checker.cpp           # Data loading verification
├── csv_to_rdf.py                 # CSV → RDF converter
└── README.md                     # This file
```

## Data Flow
```
NTSB Reports → Pattern Matching → User Validation → CSV Output → RDF Knowledge Graph
```

## Features
- Dual annotation mode (automatic + manual)
- Session persistence via progress tracking
- Color-coded highlighting for validation
- CSV export for downstream processing
- RDF knowledge graph generation

## System Architecture
Complete workflow from raw data through annotation to RDF knowledge graph generation:

![Causal Annotation System Diagram](https://raw.githubusercontent.com/falcontologist/cu-cspb2270-2025-final_project/main/system_diagram_dark.png)
