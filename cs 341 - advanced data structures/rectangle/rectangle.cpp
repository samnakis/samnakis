#include "rectangle.h"

class Rectangle {
    Rectangle::Rectangle(int x, int y) {
        w = x;
        h = y;
    }

    int Rectangle::area() {
        return w*h;
    } // end rect area

    int Rectangle::perm() {
        return 2*w + 2*h;
    } // end rect perimeter

    void Rectangle::print() {
        cout << "Width: " << w << endl; << "Height: " << h << endl;
    }

    void Rectangle::setw(int x) {
        w = x;
    }

    void Rectangle::seth(int y) {
        h = y;
    }
}; // end class Rectangle