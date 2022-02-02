#include "set.h"
#include "dictionary.h"
#include <bitset>

int main()
{

    ///////////////////////////////////////////////////////////
    // !! PART THREE !!
    Dictionary DIC(2);
    char *array = new char[2];
    array[0] = 255;
    array[1] = 3;

    DIC.fillTable();

    DIC.initialize(array);
    cout << "\n! PART THREE: " << endl;
    cout << "Array: ";
    for (int i = 0; i < 2; i++)
    {
        cout << bitset<8>(array[i]) << " ";
    }

    //from 0 to 17 how many of bits b=1;
    cout << DIC.rank(25, 1);
    cout << endl;

    DIC.select(3, 1);
    ///////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // !! PART TWO !!
    char *bitLoader = new char[2];
    bitLoader[0] = 45;
    bitLoader[1] = 77;

    char *bitTwo = new char[2];
    bitTwo[0] = 33;
    bitTwo[1] = 87;

    Set First = Set(2);
    Set Second = Set(2);

    First.initialize(bitLoader);
    Second.initialize(bitTwo);

    First.setBit(1, 1);
    First.setBit(0, 1);

    cout << "\n\n! PART TWO: " << endl;

    cout << "  FIRST SET: " << endl;
    First.printSet();

    cout << "  SECOND SET: " << endl;
    Second.printSet();

    cout << First.difference(Second);
    cout << " FIRST DIFF SECOND:" << endl;
    Second.printSet();
    Second.initialize(bitTwo);

    cout << First.intersection(Second);
    cout << " FIRST INT SECOND: " << endl;
    Second.printSet();
    Second.initialize(bitTwo);

    cout << First.onion(Second);
    cout << " FIRST UNION SECOND: " << endl;
    Second.printSet();
    Second.initialize(bitTwo);

    delete[] bitLoader;
    ///////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // !! PART ONE !!

    cout << "\n\n! PART ONE: " << endl;
    BitArray b(1);
    char *a = new char[1];
    a[0] = 128;
    b.initialize(a);

    cout << "bit at position 0:  " << (int)b.get(0) << endl;
    cout << "Starting Array: " << endl
         << b << endl;

    b.set(1, 3);
    cout << "Set:" << endl;
    cout << b << endl;

    b.clear();
    cout << "Clear:" << endl;
    cout << b << endl;

    b.complement();
    cout << "Complement:" << endl;
    cout << b << endl;

    b.flip(2);
    cout << "Flip(2):" << endl;
    cout << b << endl;

    ///////////////////////////////////////////////////////////

    return 0;
}