#include <iostream>
#include <string>

using namespace std;

// types of polymorphism

// polymorphism is the idea that an object or a thing can be interpreted or thought of multiple ways

// 1. virtual member functions
// 2. name overloading - an entity that shares a name, but not the parameters
// 3. operator overloading - an operator has a different implementation based on context

// const as an identifier/qualifier is used in a million different ways. function must be given a constant integer (one that is not allowed to change)
// cannot send variable input into const

void printArray(const int * const a, const int size)
{
    // the const in front of size prevents size from being modified in the function
    // the const in front of int * has the same purpose
    // the const just in front of a specifies that whatever a points to also cannot change
    for (int x=0; x < size; x++)
        cout << a[x] << " ";
    cout << endl;
} // end printArray (int)

void printArray(const string * const a, const int size)
{
    cout << "string time!!!!!!!!!!" << endl;
    for (int x=0; x < size; x++)
        cout << a[x] << " ";
    cout << endl;
} // end printArray (string)

// the printArrays show name overloading. they share a name but one deals with ints and one deals with strings (different parameters)

int main() {
    int b[4] = {2, 4, 6, 8};
    string c[4] = {"two", "four", "six", "eight"};

    int s = 4;

    printArray(b, s);
    printArray(c, s);

    return 0;
}

// auxiliary notes
// 1. if you have a virtual function in a class, you must have a virtual destructor as well
// 2. a pure virtual function - a virtual function where you want to require derived classes to redefine
// 3. a pure abstract class is a class that contains only pure virtual functions
// -- for example, if we created a Shape class, from which Rectangle, Square, and Triangle inherited, it would make sense for Shape to be a pure virtual class
// 4. you cannot create virtual constructors