#include <iostream>

int main(void){
    double x {};

    std::cout << "Enter the value of x: ";
    std::cin >> x;

    // if x < -1 - one formule, else if x <= 0 other one, else (x > 0)
    double result = x < -1.0 ? x / (x - 1) : x <= 0 ? x + x*x*x 
                                                    : 4 + (1 / (x*x*x)) - (1 / (x*x*x*x));
    
    std::cout << "Result: " << result << "\n";

    return 0;
}
