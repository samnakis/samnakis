#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
    private:
        int size; // number of elements in the stack
        T * data; // pointer to the internal array for the stack
        int top; // this int tells me which array position in data is at the top of the stack

    public:
        // this constructor creates a 1 parameter constructor; however, if no parameter is given, it will assume tge creation of a stack of size 10 (essentially a default constructor as well)
        Stack(int = 10); // the default constructor, with a default stack size of 10
        ~Stack(); // we wil have to specify this destructor

        // this const usage means that the function cannot change ANYTHING in the class
        bool isEmpty() const {return top == -1;}
        bool isFull() const {return top == size - 1;}

        // the actual meaty functions
        bool pop(T &); // pop an element off the stack, put it in the parameter, and designate success
        bool push(const T &); // push an element on to the stack
} // end stack (template)

#endif