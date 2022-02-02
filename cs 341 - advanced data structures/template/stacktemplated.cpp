#include "stacktemplated.h"

template<typename T>
Stack<T>::Stack(int s) {
    if (s > 0)
        size = s;
    else
        size = 10;
    top = -1;
    data = new T[size]
} // end constructor

// ternary operators - operators that work on THREE arguments

// alternate definition of constructor above using different syntax
// template<typename T>
// Stack<T>::Stack(int s) : top(-1), size(s > 0 ? s : 10), data(new T[size]) {}

template<typename T>
Stack<T>::~Stack() {delete [] data;} // end destructor

template<typename T>
bool Stack<T>::push(const T & pushValue) {
    if (isFull())
        return false;

    data[++top] = pushValue;
    return true;
} // end function push

// this uses lazy deletion which is a key cs concept
template<typename T>
bool Stack<T>::pop(T & popLocation) {
    if (isEmpty())
        return false;

    popLocation = data[top--];
    return true;
} // end function pop