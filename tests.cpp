// This code for testing functions is AI-generated

#include "constructicon-simple.h"
#include <iostream>
#include <cstdlib>
#include <regex>

namespace CC = CausalConstructicon;

// Test function to verify static initialization (moved from library file)
bool test_initialization() {
    // Call getters to access the data populated by the static Initializer
    size_t num_constructions = CC::getConstructions().size();
    size_t num_patterns = CC::getPatterns().size();
    
    std::cout << "--- CausalConstructicon Initialization Check ---" << std::endl;
    
    if (num_constructions > 0 && num_patterns > 0) {
        std::cout << "✅ SUCCESS: Static Initialization Completed. (Loaded " << num_constructions << " C & " << num_patterns << " P)" << std::endl;
        return true;
    } else {
        std::cerr << "❌ FAILURE: Static Initialization Failed (C: " << num_constructions << ", P: " << num_patterns << ")" << std::endl;
        return false;
    }
}


int main() {
    int failures = 0;
    std::cout << "--- CausalConstructicon Minimal Tests ---" << std::endl;

    // Test 1: Initialization and Getters
    std::cout << "Test 1: Initialization (Success if data is loaded) ... ";
    if (!test_initialization()) {
        failures++;
    } else {
        // The initialization test already printed status
    }
    
    // Test Data
    CausalConstruction test_c = {"T999", CausalDegree::Facilitate, CausalOrder::CE, "Test template", "Test example"};
    CausalPattern test_p = {"Test pattern", std::regex("test pattern", std::regex::icase), {"T999"}};
    
    size_t initial_c_size = CC::getConstructions().size();
    size_t initial_p_size = CC::getPatterns().size();
    
    std::cout << "------------------------------------------" << std::endl;

    // Test 2: addConstruction (Unique Add)
    std::cout << "Test 2: addConstruction (Unique) ... ";
    CC::addConstruction(test_c);
    if (CC::getConstructions().size() == initial_c_size + 1) {
        std::cout << "OK" << std::endl;
    } else {
        std::cerr << "FAIL: Size did not increase." << std::endl;
        failures++;
    }

    // Test 3: addConstruction (Duplicate Skip)
    std::cout << "Test 3: addConstruction (Duplicate Skip) ... ";
    CC::addConstruction(test_c); // Attempt to add the same item
    if (CC::getConstructions().size() == initial_c_size + 1) {
        std::cout << "OK" << std::endl;
    } else {
        std::cerr << "FAIL: Duplicate added." << std::endl;
        failures++;
    }

    // Test 4: findConstructionByID (Found)
    std::cout << "Test 4: findConstructionByID (Found) ... ";
    if (CC::findConstructionByID("T999") != nullptr) {
        std::cout << "OK" << std::endl;
    } else {
        std::cerr << "FAIL: Could not find added ID T999." << std::endl;
        failures++;
    }

    // Test 5: findConstructionByID (Not Found)
    std::cout << "Test 5: findConstructionByID (Not Found) ... ";
    if (CC::findConstructionByID("Z999") == nullptr) {
        std::cout << "OK" << std::endl;
    } else {
        std::cerr << "FAIL: Found non-existent ID Z999." << std::endl;
        failures++;
    }

    // Test 6: addPattern
    std::cout << "Test 6: addPattern (Unique Add) ... ";
    CC::addPattern(test_p);
    if (CC::getPatterns().size() == initial_p_size + 1) {
        std::cout << "OK" << std::endl;
    } else {
        std::cerr << "FAIL: Pattern failed to add." << std::endl;
        failures++;
    }

    std::cout << "\n--- Test Summary ---\n" << std::endl;
    if (failures == 0) {
        std::cout << "✅ All tests passed." << std::endl;
        return EXIT_SUCCESS;
    } else {
        std::cerr << "❌ " << failures << " test(s) failed." << std::endl;
        return EXIT_FAILURE;
    }
}
