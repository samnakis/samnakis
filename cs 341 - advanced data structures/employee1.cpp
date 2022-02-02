#include "employee1.h"

int Employee::count = 0;
// default constructor
Employee::Employee() : birthDay(0), birthMonth(0), birthYear(0) {
    firstName = " ";
    lastName = " ";
    nickName = " ";
    // you can't explicitly set these values because they are const
    // birthDay = 0;
    // birthMonth = 0;
    // birthYear = 0;
    count++;
}

//destructor
Employee::~Employee() {
    count--;
}

void Employee::printInfo() {
    cout << getName() << endl;
    cout << " Born on: " << birthMonth << "/" << birthDay << "/" << birthYear << endl;
    cout << "Hired on: " << hireMonth << "/" << hireDay << "/" << hireYear << endl;

    // when we access a class' data members within a class function, we can directly refer to it. however, what's really going on underneath is that the compiler is using that variable name and "composing" a true variable name based on where you are. it does so using a memory location that points to itself called the "this pointer"

    // the statement below uses "this" implicitly and explicitly
    // cout << birthYear << " " << this->birthYear << " " << (*this).birthYear << endl;

    // this pointers have a lot of uses, but generally you don't need them under normal circumstances. so don't just jam them in your code. here are some use-scenarios for them
    // 1) when clarity is needed about which variable you are referring to each other
    // 2) cascaded member function calls with a class reference return value

}

// setNickName is a friend function of class Employee
// it doesn't have Employee:: in front bc not in class
void setNickName(Employee & buddy, string n) {
    buddy.nickName = n;
}