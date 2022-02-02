#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    // typecasting is the idea of changing a variable type explicitly
    // this is an inherently dangerous process, and you need to know what you are doing with this

    // since we know now that every variable, class, etc. is really just a memory location followed by some number of bitset, all we have to do to "change" the type of a variable is tell it something else

    char c = 'a'; // this has an ascii value of 97

    cout << c << endl;
    cout << (int) c << endl;

    // // omg infinite loop
    // cout << setw(5) << "cec" << setw(5) << "char" << endl;
    // for(char x = 0; x < 256; x++) {
    //     cout << setw(5) << (int) x << setw(5) << x << endl;
    // }

    // yay
    cout << setw(5) << "cec" << setw(5) << "char" << endl;
    for(char x = 0; x < 256; x++) {
        cout << setw(5) << (int) x << setw(5) << (char) x << endl;
    }

    // variable casting is different from pointer casting in some important ways:
    // you can't just cast whatever you want to something else

    // this won't work
    // cout << (ostream) c << endl;

    // some of these, where the data type is "bigger", work naturally
    cout << (float) c << endl;
    cout << (double) c << endl;

    // when data types are "smaller", weirdness happens. in this case, truncation!
    double d = 12.3;
    cout << (int) d << endl;

    char * dPtr = & d;
    cout << *dPtr << endl;
    cout << dPtr << setw(12) << *dPtr << endl;
    cout << (int *) cPtr << (* (int *) dPtr) << endl;

    // useful data types for the project
    // can use smaller ones to save space (ex: small numbers in a big array)
    uint8_t g; // an unsigned int using 8 bits with a little mr. t
    uint16_t h; // same with 16 bits
    uint32_t j; // same with 32 bits, this one is just normal unsigned int
    uint64_t k; // same with 64 bits

    // how to declare literal values of binary types
    uint32_t p = 63;
    cout << p << endl;
    uint32_t q = 0b0000111; // explicitly written binary number
    cout << q << endl;
    p = 0xFFFF; // explicitly written hexidecimal number
    cout << p << endl;

    return 0;
}