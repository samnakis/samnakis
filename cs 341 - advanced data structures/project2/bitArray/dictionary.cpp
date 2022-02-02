#include "dictionary.h"
using namespace std;

// constructor
Dictionary::Dictionary()
{
    data = BitArray();
}

Dictionary::Dictionary(int i)
{
    data = BitArray(i);
}

// given a character string, set the data appropriately
void Dictionary::initialize(char *a)
{
    data.initialize(a);
}

// Destructor
Dictionary::~Dictionary()
{
}

// naive rank/select in a range

// computes how many of the bit b are in the interval [i,j), defaults to (b=1)
int Dictionary::rank_range(int i, int j, int b)
{
    int x = i;
    int y = j;
    int count = 0;
    for (x; x < y; x++)
    {
        if (data.get(x) == b)
            count++;
    }
    return count;
}

// returns the position of the kth bit b in the interval [i,j), defaults to (b=1)
// Counts bs until you have k bs and then gives position
int Dictionary::select_range(int i, int j, int k, int b)
{
    int position = 0;
    int bCount = 0;
    for (int index = 0; index < (j - i); index++)
    {
        if (data.get(index) == b)
            bCount++;

        if (bCount == k)
            return position;

        position++;
    }

    cout << "COULDN'T FIND B's POSITION IN RANGE" << endl;
    return 0;
}

// using lookup table
// computes how many of the bit b are in the interval [0,j), defaults to (b=1)
int Dictionary::rank(int j, int b)
{

    int numFullBytes = j / 8;
    int lastByteCarry = j % 8;
    int count = 0;

    for (int i = 0; i < numFullBytes; i++)
    {
        if (b == 0)
        {
            count += 8 - (LookupTable[(int)data.get8(i)]);
        }
        else if (b == 1)
        {
            count += LookupTable[(int)data.get8(i)];
        }
    }

    cout << "\n\nNumber of " << b << "'s in 0 to " << j << ": ";
    return count += rank_range(numFullBytes * 8, j, b);
}

// returns the position of the kth bit b in the dictionary, defaults to (b=1)
int Dictionary::select(int k, int b)
{
    int index = 0;
    int count = 0;
    int position = 0;

    while (count < k)
    {
        if (b == 0)
        {
            count += 8 - (LookupTable[(int)data.get8(index)]);
        }
        else if (b == 1)
        {
            count += LookupTable[(int)data.get8(index)];
        }
        position += 8;
        index++;
    }

    position -= 8;
    index--;
    if (b == 0)
    {
        count -= 8 - (LookupTable[(int)data.get8(index)]);
    }
    else if (b == 1)
    {
        count -= LookupTable[(int)data.get8(index)];
    }

    for (int index = position; index < (data.length()); index++)
    {
        if (data.get(index) == b)
            count++;

        if (count == k)
        {
            cout << "The " << k << " bit " << b << " is at position: " << position << endl;
            return position;
        }

        position++;
    }

    return 0;
}

// fills the lookup table
void Dictionary::fillTable()
{
    char *holder = new char[1];

    Dictionary DIC = Dictionary();

    for (int i = 0; i < 256; i++)
    {
        holder[0] = i;
        DIC.initialize(holder);
        LookupTable[i] = DIC.rank_range(0, 8, 1);
    }

    delete[] holder;
}
