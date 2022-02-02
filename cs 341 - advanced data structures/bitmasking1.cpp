#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    // a mask defines a subset of bits that you want to "keep" or "modify"
    // 0b11110000 is a mask that says you want to "keep" the first 4 bits
    // bitmasking is the act of applying a mask to a variable (or a value)

    cout << 7 & 0b11110000 << endl;

    // there are three different "types" of bitmasking:
    // 1. bitwise AND - extracts (keeps the value of) the bits from the variable where the mask is 1
    // 2. bitwise OR - sets (gives a value of 1) the bits from the variable where the mask is 1
    // 3. bitwise XOR - flip the bits from the variable where the mask is 1

    uint16_t bigbyte = 0b1010101010101010;
    uint16_t bigmask = 0x00FF;
    cout << (bitset<16>) (bigbyte & bigmask) << endl;
    cout << (bitset<16>) (bigbyte & (bigmask<< 8)) << endl;

    return 0;
}