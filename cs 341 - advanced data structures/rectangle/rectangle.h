#ifndef RETANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <math.h>
using namespace std;

#include "rectangle.h"

class Rectangle {
    private:
        int w, h;

    public:
        Rectangle() {} // default constructor
        Rectangle(int x, int y);

        void setw(int x);
        void seth(int y);
        virtual int area();
        virtual int perm();
        virtual void print();
}; // end class Rectangle

#endif