#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

#include "phonenumber.h"

class Employee {
    private: // private is the default for classes
        string firstName;
        string lastName;
        string nickName;
        const unsigned int birthDay;
        const unsigned int birthMonth;
        const unsigned int birthYear;

        unsigned int hireDay;
        unsigned int hireMonth;
        unsigned int hireYear;

        // a static variable is created for the class as a whole, not for each individual instance
        // in other words, employee will have ONE copy of count, shared across all instances of employee
        static int count; // keeps track of how many total employees there are

    public:
        // boilerplate
        Employee();
        ~Employee();

        // access functions
        string getName() {return firstName + " \"" + nickName + "\" " + lastName;}
        int getCount() {return count;}
        void setName(string f, string l, string n = "") { firstName = f; lastName = l; nickName = n;}
        void setHire(int m, int d, int y) { hireMonth = m; hireDay = d; hireYear = y;}

        // utility functions - useful things that you want to have the class be able to do
        void printInfo();

        // friend functions
        friend void setNickname(Employee &, string);
};

#endif