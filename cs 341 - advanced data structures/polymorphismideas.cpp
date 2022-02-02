// this code will not run because we are not filling in details

// we will have a base Shape class, from which Rectangle and Square inherit as a inheritance chain. we will also inherit Triangle from Shape directly

// the Shape base class has a virtual function called area that each inherited class redefines for their shape

// Rectangle adds another virtual function to compute its diagonal, which Square in herits

int main() {
    Rectangle r(3, 12);
    Square s(12);
    Triangle t(1, 2, 5);

    Shape * shape1 = &r;
    Shape * shape2 = &s;
    Shape * shape3 = &t;

    Rectangle

    // each virtual area function will execute according to the correct shape
    shape1->area();
    shape2->area();
    shape3->area();

    // this will NOT work, because the Shape base class doesn't have the diagonal function, even though the objects pointed to, do
    shape1->diagonal();
    shape2->diagonal();

    // this WILL work
    rect1->diagonal();
    rect2->diagonal();

    return 0;
}