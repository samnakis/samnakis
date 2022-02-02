// Author(s):
// File: set.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A set class that supports union, intersection, and relative complement.

#ifndef SET_H
#define SET_H

#include "bitarray.h"

class Set
{
protected:
    BitArray data;
    int CARDINALITY;

public:
    // Class maintenance details
    Set();                   // constructor
    Set(int);                // Send the size in bytes
    void initialize(char *); // given a character string, set the data appropriately

    ~Set(); // default destructor

    // Allow read access to protected variable names
    inline int cardinality() const;

    // Bit read/write functions
    bool onion(Set &targetSet);        // computes the union with the input set and stores it here
    bool intersection(Set &targetSet); // computes the intersection with the input set and stores it here
    bool difference(Set &);            // computes the relative difference between this set and the input set and stores it here
    bool setBit(int, int);
    bool getBit(int);
    void printSet();

}; // end class Set

#endif
