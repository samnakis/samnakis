#include "set.h"
using namespace std;

// Things we need to do
// Update CARDINALITY when we init
// Check that CARDINALITY is the same for both sets for all of the operations
// Something weird is happening with constructor

// default constructor
Set::Set()
{
    CARDINALITY = 0;
    BitArray data();
}

// constructor (sends size in bytes)
Set::Set(int size)
{
    CARDINALITY = 0;
    data = BitArray(size);
}

// given a character string, set the data appropriately
void Set::initialize(char *a)
{
    data.initialize(a);

    CARDINALITY = data.length(); // I Think this works not really sure?
}

// default destructor
Set::~Set()
{
}

bool Set::setBit(int val, int index)
{
    data.set(val, index);
    return true;
}

bool Set::getBit(int index)
{
    return data.get(index);
}

// Allow read access to protected variable names
inline int Set::cardinality() const
{
    return CARDINALITY;
}

// Bit read/write functions
// computes the union with the input set and stores it here
// The bit string for the union is the bitwise OR of the bit string for the two sets.
bool Set::onion(Set &targetSet)
{
    if (CARDINALITY != targetSet.CARDINALITY)
        return false;

    // If either bit == 1, set to 1. If not, set to 0
    for (int i = 0; i < CARDINALITY; i++)
    {
        if (data.get(i) || targetSet.getBit(i))
            targetSet.setBit(1, i);
        else
            targetSet.setBit(0, i);
    }
    return true;
}

// computes the intersection with the input set and stores it here
// The bit string for the intersection is the bitwise AND of the bit strings for the two sets.
bool Set::intersection(Set &targetSet)
{
    if (CARDINALITY != targetSet.CARDINALITY)
        return false;

    // if both bits are 1, set to 1. If not, set to 0
    for (int i = 0; i < CARDINALITY; i++)
    {
        if (data.get(i) && targetSet.getBit(i))
            targetSet.setBit(1, i);
        else
            targetSet.setBit(0, i);
    }
    return true;
}

// computes the relative difference between this set and the input set and stores it here
// if the bits match - 0 if they are different - 1
bool Set::difference(Set &targetSet)
{
    if (CARDINALITY != targetSet.CARDINALITY)
        return false;

    for (int i = 0; i < CARDINALITY; i++)
    {
        if ((data.get(i) == targetSet.getBit(i)))
        {
            targetSet.setBit(0, i);
        }
        else
        {
            targetSet.setBit(1, i);
        }
    }
    return true;
}

void Set::printSet()
{
    cout << data << endl;
}