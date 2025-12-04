#include "constructicon-simple.h"
#include <iostream>

int main() {
    std::cout << "\n*** Inventory ***" << std::endl;
    std::cout << "Causal Constructions: " << CausalConstructicon::getConstructions().size() << std::endl;
    std::cout << "Causal Patterns: " << CausalConstructicon::getPatterns().size() << std::endl;
    std::cout << "Accident Records: " << Annotator::records.size() << std::endl;
    std::cout << "Annotations: " << Annotator::getAnnotations().size() << std::endl;
    
    // construction sample 
    if (!CausalConstructicon::getConstructions().empty()) {
        const auto& c = CausalConstructicon::getConstructions()[0];
        std::cout << "\nSample Construction:" << std::endl;
        std::cout << "ID: " << c.id << std::endl;
        std::cout << "Template: " << c.trigger_template << std::endl;
        std::cout << "Example: " << c.example << std::endl; 
    } else {
        std::cout << "\nSample construction: (none yet)" << std::endl;
    }
    
    // pattern sample
    if (!CausalConstructicon::getPatterns().empty()) {
        const auto& p = CausalConstructicon::getPatterns()[0];
        std::cout << "\nSample Pattern:" << std::endl;
        std::cout << "Description: " << p.description << std::endl;
        std::cout << "Construction IDs: ";
        for (const auto& id : p.ids) std::cout << id << " ";
        std::cout << std::endl;
    } else {
        std::cout << "\nSample pattern: (none yet)" << std::endl;
    }
    
    // record sample
    if (!Annotator::records.empty()) {
        const auto& r = Annotator::records[0];
        std::cout << "\nSample Record:" << std::endl;
        std::cout << "ID: " << r.recordID << std::endl;
        std::cout << "Cause: " << r.probableCause << std::endl;
    } else {
        std::cout << "\nSample record: (none yet)" << std::endl;
    }   
    
    // annotation sample
    if (!Annotator::getAnnotations().empty()) {
        const auto& a = Annotator::getAnnotations()[0];
        std::cout << "\nSample Annotation:" << std::endl;
        std::cout << "Construction ID: " << a.constructionID << std::endl;
        std::cout << "Record ID: " << a.recordID << std::endl;
        std::cout << "Trigger: " << a.trigger << std::endl;
        std::cout << "Cause: " << a.cause << std::endl;
        std::cout << "Effect: " << a.effect << std::endl;
    } else {
        std::cout << "\nSample annotation: (none yet)" << std::endl;
    }
    
    return 0;
}