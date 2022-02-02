//Your task is to create bitarray.cpp to finish the implementation of the class BitArray.
//You will find that these functions are very simple to understand,
//and aside from the bitwise operations, there isn’t much that is complicated to do here.
//You should do this ASAP. One word of warning. If you walk off of the edge of your array, you will be sad.
//You are playing with bits now, and that ain’t no joke.

#include <ostream>
#include <fstream>
#include <bitset>
#include <stdint.h>
#include <iomanip>
using namespace std;

#include "bitarray.h"

//Constructor
BitArray::BitArray(int numBytes)
{
    LENGTH = numBytes * 8;
    BYTES = numBytes;
}

//Destructor
BitArray::~BitArray()
{
    // stays empty
} //end destructor

// sets all bits to 0
void BitArray::clear()
{ // **WORKING**
    for (int i = 0; i < BYTES; i++)
        data[i] = 0;
}

// given a character string, copy its contents here
void BitArray::initialize(char *a)
{ // **WORKING**
    data = a;
}

// There are three different "types" of bitmasking:
// 1) Bitwise AND -- extracts (keeps the value) the bits from the variable where the mask is 1
// 2) Bitwise OR -- sets (gives a value of 1) the bits from the variable where the mask is 1
// 3) Bitwise XOR -- flip the bits from the variable where the mask is 1

bool BitArray::set(int b, int p)
{ // **WORKING, no bool condition**
    // sets a bit b (default 1) at position p
    int arrayPos = p / 8;
    int bitPos = p % 8;

    char mask = 1;

    mask = (mask << (7 - bitPos));

    if (p >= (LENGTH) || p < 0) // Probably works
    {
        return false;
    }
    if (b == 1)
    {
        data[arrayPos] = (data[arrayPos] | mask);
    }
    if (b == 0)
    {
        data[arrayPos] = (data[arrayPos] & (~mask));
    }

    return true;
}

bool BitArray::flip(int p)
{ // **WORKING, no bool condition**
    // flips the bit at position p

    int arrayPos = p / 8;
    int bitPos = p % 8;

    if (p >= (LENGTH) || p < 0) // Probably works
    {
        return false;
    }

    char mask = 1;

    mask = (mask << (7 - bitPos));

    data[arrayPos] = (data[arrayPos] ^ mask);

    return true;
}

char BitArray::get(int p)
{ // **WORKING**
    // returns the value of the bit at position p

    // bitwise & with a mask, that has 1 at the pth bit
    // This will return either 0 or not 0
    // 0 means the bit is 0, not 0 means it's 1

    int arrayPos = p / 8;
    int bitPos = p % 8;

    char mask = 1;

    mask = (mask << (7 - bitPos));

    if ((data[arrayPos] & mask) == 0)
        return 0;

    return 1;
}

void BitArray::complement()
{ // **WORKING**
    // flips 1's and 0's in bit array
    // XOR with a 255 mask on every char
    char mask = 255;

    for (int i = 0; i < BYTES; i++)
    {
        data[i] = (data[i] ^ mask);
    }
}

// This function allows easy printing of a bit array
// This is an overloaded operator for the <<, so that you can cout a BitArray
ostream &operator<<(ostream &out, BitArray &array)
{ // I changed this b/c it didn't make any sense to me... idk i'll ask andrew^2 about it
    int NUMPERLINE = 4;
    int numPrinted = 0;
    for (int x = 0; x < array.length(); x++)
    {
        // if (array.get(x)) { **commented out
        out.width(4);
        // out << x; // Commented out **
        out << (int)array.get(x); // Added
        numPrinted++;
        if (numPrinted % NUMPERLINE == 0)
            out << "\n";
        //} // end if ** commented out **
    } // end for
    return out;
} // end ostream & operator <<

// return a char that contains the decimal version of the bit interval [p,p+8).
// Hint: You may need to recast the return value of get to treat it like an unsigned int, but the char return value will be useful.
uint8_t BitArray::get8(int x)
{
    return data[x];
    // return character arrays
    // needs to be an unsigned int and not a charater
}
