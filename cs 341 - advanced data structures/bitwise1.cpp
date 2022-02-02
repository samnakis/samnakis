#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    // these use the stuff from the ascii table
    // char x = 7; // beep!
    char x = 15;
    char y = 87;

    cout << x << " " << y << endl;

    unsigned int z = 0;
    // int z(0) // calls the int constructor

    z = x & y; // store the bitwise and result in a variable

    bitset<8> c = x;
    bitset<8> d = y;

    cout << setw(25) << " " setw(6) << "x" << setw(10) << "y" << endl;
    cout << setw(25) << " " setw(6) << "-" << setw(10) << "-" << endl;
    cout << setw(25) << "before operations: " setw(10) << c << setw(10) << d << endl;
    // cout << "bitwise AND: " << z << endl;
    cout << "bitwise AND: " << setw(30) << (c & d) << endl;
    cout << "bitwise OR: " << setw(30) << (c | d) << endl;
    cout << "bitwise XOR: " << setw(30) << (c ^ d) << endl;
    cout << "bitwise 1's complement: " << setw(10) << ~c << setw(10) << ~d << endl;


    // some more bitwise operations
    // left shift and right shift

    // If you think about it, left-shift of 1 multiplies the number by 2.
	cout << setw(25) << "left-shift: " << setw(10) << (c << 2) << setw(10) << (d << 2) << endl;	

	// If you think about it, right-shift of 1 divides the number by 2.
	cout << setw(25) << "right-shift: " << setw(10) << (c >> 2) << setw(10) << (d >> 2) << endl;	

    return 0;
}