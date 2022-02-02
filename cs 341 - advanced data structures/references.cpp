#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x = 6;
    int y = 11;
    int z = 12;

    // creates a reference variable (or an alias)
    // a reference refers to the "address of a variable" 
    int & w = z;

    z = 23;
    cout << z << endl;
    cout << w << endl;
    cout << endl << endl;

    // zPtr is a pointer, which is a variable that stores a memory address
    int * zPtr;
    zPtr = &z;

    cout << zPtr << endl;
    cout << &z << endl;
    cout << &w << endl;

    cout << &zPtr << endl;

    *zPtr =14;
    cout << *&zPtr << endl;
    cout << z << endl;

    // & and * are sort of opposites of each other

    // do not try this at home (or maybe you can)
    cout << zPtr + 6400000000 << endl;

    int a[10];
    // another way to create an array
    int * b = new int[10];
    cout << b[10000000] << endl;

    // new and delete stuff
    int * c = new int;

    // deletes must be paired with corresponding news, sort of like a right brace, the difference is that you have to understand the scope of the variable to determine the right time to delete it
    delete [] b;
    delete c;
}