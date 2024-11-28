#include <iostream>
#include <cassert>
#include <cmath>
#include "se.lab2.cpp"

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
void testValidateStep() {
    double step;

    // Valid step
    step = 0.5;
    validateStep(step); // Should not throw an error

    // Invalid step (negative)
    step = -0.5;
    try {
        validateStep(step);
        assert(false); // Fail the test if no exception is thrown
    } catch (const std::invalid_argument &e) {
        assert(true); // Pass the test if exception is caught
    }

    // Invalid step (zero)
    step = 0.0;
    try {
        validateStep(step);
        assert(false); // Fail the test if no exception is thrown
    } catch (const std::invalid_argument &e) {
        assert(true); // Pass the test if exception is caught
    }

    std::cout << "testValidateStep passed.\n";
}

// Test for calculateFormulaForXLessThanZero
void testCalculateFormulaForXLessThanZero() {
    // Test for n = 3 (example expected result)
    double result = calculateFormulaForXLessThanZero(3);
    assert(fabs(result - 0.125) < 0.0001); 

    // Edge case: n = 0
    result = calculateFormulaForXLessThanZero(0);
    assert(result == 1); 

    std::cout << "testCalculateFormulaForXLessThanZero passed.\n";
}

// Test for calculateFormulaForXGreaterThanOrEqualToZero
void testCalculateFormulaForXGreaterThanOrEqualToZero() {
    // Test for x = 1, n = 3 (example expected result)
    double result = calculateFormulaForXGreaterThanOrEqualToZero(1, 3);
    assert(fabs(result - 2.5) < 0.0001); 
    // Division by zero case
    result = calculateFormulaForXGreaterThanOrEqualToZero(-3, 1); // x + 3j = 0 for j = 1
    assert(result == 0); // Should return 0 and not crash

    std::cout << "testCalculateFormulaForXGreaterThanOrEqualToZero passed.\n";
}

// Main function to run all tests
int main() {
    std::cout << "Running tests...\n";

    testIsValidRange();
    testValidateStep();
    testCalculateFormulaForXLessThanZero();
    testCalculateFormulaForXGreaterThanOrEqualToZero();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
