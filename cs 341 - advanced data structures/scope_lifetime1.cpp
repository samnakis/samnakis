#include <iostream>
#include <iomanip>
using namespace std;

#include "employee1.h"

int main() {
    // scope is the region or section of code where you can access a variable
    // this is the standard thing that you have always understood about how
    // long variables last

    // lifetime of a variable is the duration for which a variable is "alive"
    // "alive" means when a variable is in a valid state

    {
        // this is a local variable that dies when this scope ends
        // the lifetime of a local variable is its scope
        int x = 12;
    }

    // lifetime does not have to equal scope - examples we will have already seen are:
    // 1. variables created on the heap
    // 2. data members inside of a class instance
    // 3. static variables - both in classes and in functions

    Employee dan;
    dan.setName("dan", "the man");
    Employee fran;
    fran.setName("fran", "the plan");
    {
        Employee doomedtodie;
        cout << "count inside the scope: " << doomedtodie.getCount() << endl;
    }

    dan.printInfo();
    cout << "count outside the scope: " << dan.getCount() << endl;
    cout << "count outside the scope: " << fran.getCount() << endl;

    // test friendship
    setNickname(dan, "literally anything but dc");
    dan.printInfo();

    return 0;
}
