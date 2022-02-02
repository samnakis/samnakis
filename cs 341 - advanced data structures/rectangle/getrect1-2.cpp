#include <iostream>
#include <math.h>
using namespace std;

// creating a class in c++
class Rectangle {
    private: // default area
        // private is reseved for data and functions that are not supposed to be accesible outside of the class
        int w, h;

    public:
        // a place to store interfaces usually
        Rectangle(); // default constructor
        Rectangle(int x, int y) {  // input variables & defining a class inside
            w = x;
            h = y;
        }; // end xy constructor

        int area();
        int perm();
}; // end class Rectangle

class Square: public Rectangle {
    private:
        int side;

    public:
        Square();
        Square(int x, int y) : Rectangle(x,y) {side = x;}

    // use virtual for polymorphism
    virtual int area();
    virtual int perm();
}; // end class Square

// defining a class outside
int Rectangle::area() {
    return w*h;
} // end rect area

int Rectangle::perm() {
    return 2*w + 2*h;
} // end rect perimeter

int Square::area() {
    cout << "Square: ";
    return side*side;
} // end square area

int Square::perm() {
    cout << "Square: ";
    return 4*side;
} // end square permimeter

int main() {
    // driver program area
    Rectangle myRect(15, 10);
    Square mySquare(12, 12);

    // another way to create a class instance
    Rectangle * pointToMyRect = new Rectangle(20, 20);

    cout << myRect.area() << endl;
    // have to dereference before you find the area
    cout << (*pointToMyRect).area() << endl;
    // use the arrow operator to do the same thing as above
    cout << pointToMyRect->area() << endl;

    cout << endl;

    cout << mySquare.area() << endl;
    cout << mySquare.perm() << endl;

    // need to delete the pointer so no memory leaks !! if you don't, you will leave random integers floating around in thomas :(
    delete pointToMyRect;

    return 0;
}