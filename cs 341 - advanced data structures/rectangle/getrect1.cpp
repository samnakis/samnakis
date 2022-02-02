#include <iostream>
#include <math.h>
using namespace std;

// creating a class in c++
class Rectangle {
    private: // default area
        // private is reseved for data and functions that are not supposed to be accesible outside of the class
        int w, h;
        int * unnecessary;

    public:
        // a place to store interfaces usually
        Rectangle(); // default constructor
        Rectangle(int x, int y) {  // input variables & defining a class inside
            w = x;
            h = y;
            unnecessary = new int[100000];
        }; // end xy constructor

        // an alternate way to declaure constructors, a bit more "safe" from a software engineering perspective, because it explicity calls constructor functions
        Rectangle(int x, int y, int * z) : w(x), h(y), unnecessary(new int[1000000]) {}

        // destructor, denoted by ~
        ~Rectangle(); // when the class instance is finished, destroy it

        int area();
        int perm();

    protected:
        // only this class, friends of this class, and derived classes (descendants) have access to these items
}; // end class Rectangle

Rectangle::~Rectangle() {
    delete [] unnecessary;
}

// defining a class outside
int Rectangle::area() {
    return w*h;
} // end area

int Rectangle::perm() {
    return 2*w + 2*h;
} // end perimeter

int main() {
    // driver program area
    Rectangle myRect(15, 10);

    // another way to create a class instance
    Rectangle * pointToMyRect = new Rectangle(20, 20);

    cout << myRect.area() << endl;
    // have to dereference before you find the area
    cout << (*pointToMyRect).area() << endl;
    // use the arrow operator to do the same thing as above
    cout << pointToMyRect->area() << endl;

    // need to delete the pointer so no memory leaks !! if you don't, you will leave random integers floating around in thomas :(
    delete pointToMyRect;

    return 0;
}