#ifndef ICEBBS_H
#define ICEBBS_H

#include <iostream>
#include <string>
using namespace std;

class LicorIce {
    public:
        int shatterScore;
        int power;
        string name;

        LicorIce();
        LicorIce(int, int, string);
        ~LicorIce();
        
        void print() {cout << name << " " << shatterScore << " " << power << endl;}

        // functions to return values of the bb
        string getName() const { return name; }
        int getScore() const { return shatterScore; }
        int getPower() const { return power; }

        // friend ostream &operator<<(ostream &out, LicorIce &bb);

        // bool LicorIce::operator<(const LicorIce &right) const;
        // bool LicorIce::operator<=(const LicorIce &right) const;
        // bool LicorIce::operator>(const LicorIce &right) const;
        // bool LicorIce::operator>=(const LicorIce &right) const;
};

// // !! operator overloading !!

// // This function allows easy printing of a licorice bb
// // This is an overloaded operator for the <<, so that you can cout licorce
// ostream &operator<<(ostream &out, LicorIce &bb) {
//     cout << bb.getName();
//     return out;
// } // end ostream & operator <<

// // operators for comparing shatter scores
// // strictly less than
// bool LicorIce::operator<(const LicorIce &right) const {
//     if(shatterScore < right.getScore())
//         return true;
//     return false;
// }

// // less than or equal to
// bool LicorIce::operator<=(const LicorIce &right) const {
//     if(shatterScore <= right.getScore())
//         return true;
//     return false;
// }

// // less than or equal to
// bool LicorIce::operator>(const LicorIce &right) const {
//     if(shatterScore > right.getScore())
//         return true;
//     return false;
// }

// // less than or equal to
// bool LicorIce::operator>=(const LicorIce &right) const {
//     if(shatterScore >= right.getScore())
//         return true;
//     return false;
// }


#endif