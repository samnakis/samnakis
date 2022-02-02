// Author(s):
// File: dictionary.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A dictionary class that supports rank, select, rank_range, and select_range

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "bitarray.h"

class Dictionary
{
    // You will need some private variables to set up the lookup tables when you get to that part.
private:
    int LookupTable[256];
    /* sexiest most brilliant lookup table (not hardcoded!) <3
    int LookupTable[256] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 
        5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 
        3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 
        5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 
        3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 
        6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 
        4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8 };
    */

protected:
    BitArray data;

public:
    // Class maintenance details
    Dictionary(); // constructor
    Dictionary(int);
    void initialize(char *); // given a character string, set the data appropriately

    ~Dictionary(); // default destructor

    // Naive rank/select in a range
    int rank_range(int i, int j, int b = 1);          // computes how many of the bit b are in the interval [i,j), defaults to (b=1)
    int select_range(int i, int j, int k, int b = 1); // returns the position of the kth bit b in the interval [i,j), defaults to (b=1)

    // rank/select using a lookup table
    int rank(int j, int b = 1);   // computes how many of the bit b are in the interval [0,j), defaults to (b=1)
    int select(int k, int b = 1); // returns the position of the kth bit b in the dictionary, defaults to (b=1)

    // function to fill up the lookup table
    void fillTable();

}; // end class Set

#endif
