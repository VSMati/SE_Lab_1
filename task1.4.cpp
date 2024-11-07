#include <iostream>

int main() {
    unsigned int n { };
    std::cout << "Input an integer between 1 and 10: ";
    std::cin >> n;

    // 8^n is (2^3)^n = 2^(3n), so we can use left shift (2 << (3 * n - 1))
    unsigned int result = (n >= 0 && n <= 10) ? 1U << (3 * n) : 0;
    // If user gives wrong input - result is 0

    std::cout << result << "\n";

    return 0;
}

