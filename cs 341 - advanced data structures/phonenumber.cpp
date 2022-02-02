#include <iomanip>
using namespace std;

#include "phonenumber.h"

// overloaded stream operator can't be a member function if you want to use it with a cout really anywhere
ostream & operator<<(ostream & out, const PhoneNumber & num) {
    out << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
    return out; // enables cout << a << b << c;
} // end operator<<

istream & operator<<(istream & in, PhoneNumber & num) {
    in.ignore();    // skipping (
    in >> setw(3) >> num.areaCode;
    in.ignore(2);   // skipping ) and space
    in >> setw(3) >> num.exchange;
    in.ignore();    // skipping -
    in >> setw(4) >> num.line;
    return in;      // enables cin a >> b >> c;
} // end operator>>