#include <iostream>

int main(void){
    int k {};
    std::cout << "Input a positive integer: ";
    std::cin >> k;

    // Perform a check for the non-positive value of k and calculate y
    double y = k > 0 ? ((1.0/k) + (1.0/(k*k)) + (1.0/(k*k*k))) : -1.0;
    y == -1.0 ? std::cout << "Invalid input" : std::cout << y << "\n";
    
    return 0;
}
