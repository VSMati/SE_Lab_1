#include <iostream>
#include <cassert>
#include <cmath>
#include "se.lab2.h"

// Test for isValidRange
void testIsValidRange() {
    // Valid ranges
    assert(isValidRange(0, 1) == true);
    assert(isValidRange(-5, 0) == true);

    // Invalid ranges
    assert(isValidRange(1, 1) == false);
    assert(isValidRange(2, 1) == false);

    // Edge cases
    assert(isValidRange(0, 0.0001) == true); // Almost equal
    assert(isValidRange(-1, -1) == false);   // Equal negative numbers

    std::cout << "testIsValidRange passed.\n";
}

// Test for validateStep
void testIsStepValid() {
    // Valid steps
    assert(isStepValid(0.5) == true);
    assert(isStepValid(1.0) == true);

    // Invalid steps
    assert(isStepValid(0.0) == false);
    assert(isStepValid(-0.5) == false);

    std::cout << "testIsStepValid passed.\n";
}


// Test for calculateFormulaForXLessThanZero
void testCalculateFormulaForXLessThanZero() {
    double result;

    // Test for n = 3
    result = calculateFormulaForXLessThanZero(3);
    std::cout << "Result for n=3: " << result << std::endl;
    assert(fabs(result - 0.0) < 0.0001); 

    // Not looking into edge cases, such as n = 0, since program is interactive

    std::cout << "testCalculateFormulaForXLessThanZero passed.\n";
}


// Test for calculateFormulaForXGreaterThanOrEqualToZero
void testCalculateFormulaForXGreaterThanOrEqualToZero() {
    // Test for x = 1, n = 3 (example expected result)
    double result = calculateFormulaForXGreaterThanOrEqualToZero(1, 3);
    assert(fabs(result - 1.02143) < 0.0001); 
    // Division by zero case
    result = calculateFormulaForXGreaterThanOrEqualToZero(-3, 1); // x + 3j = 0 for j = 1
    assert(result == 0); // Should return 0 and not crash

    std::cout << "testCalculateFormulaForXGreaterThanOrEqualToZero passed.\n";
}

// Main function to run all tests
int main() {
    std::cout << "Running tests...\n";

    testIsValidRange();
    testIsStepValid();
    testCalculateFormulaForXLessThanZero();
    testCalculateFormulaForXGreaterThanOrEqualToZero();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
