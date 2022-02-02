#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber {
    // overloading provides a new meaning for the symbol
    friend ostream & operator<<(ostream &, const PhoneNumber &);
    friend istream & operator>>(istream &, PhoneNumber &);

    private:
        string areaCode;
        string exchange;
        string line;
}; // end class PhoneNumber

#endif