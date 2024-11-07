#include <iostream>

int main(void){
    double x {};
    int result {};
    std::cout << "Enter a number with a floating point: ";
    std::cin >> x;

    result = (x >= 0 && x <= 2)||(x > 7 && x < 11) ? 1 : 0 ;
    std::cout << result << "\n";
    /* if x withing 0 to 2 (both included) or 7 to 11 - output 1
    *  else output 0 */
    return 0;
}
