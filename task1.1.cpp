#include <iostream>
using namespace std;

int main(void){
    int input{ };
    cout << "Enter an integer between 33 and 255 ";
    cin >> input;

    cout << ( input >= 33 && input <= 255 ? char(input) : '\0') << "\n";

    return 0;
}
