#include <iostream>

using namespace std;

int main(void) {

    unsigned int k;
    int m, n;

    cout << "Enter a digit k (> 0): "; 
    cin >> k;
    cout << "Enter bit m (< 32): ";
    cin >> m;
    cout << "Enter bit n (< 32): "; 
    cin >> n;
    //create bitmask - mth or nth bit is 1, rest 0
    unsigned int mask_m = 1 << m;
    unsigned int mask_n = 1 << n;
    //extract bits and positions m and n
    unsigned int bit_m = (k & mask_m) >> m; //isolate at position m and shift to
    unsigned int bit_n = (k & mask_n) >> n; //least significant
    //XOR flips the bits if they are different, if same, they stay
    k = k ^ ((bit_m ^ bit_n) << m) ^ ((bit_m ^ bit_n) << n);

    cout << "Result: " << k << endl;
    return 0;
}
