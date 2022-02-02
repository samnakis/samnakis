#include "icebbs.h"

// default constructor
LicorIce::LicorIce(){
    shatterScore = 0;
    power = 0;
    name = "";
} // end default constructor

// deconstructor
LicorIce::~LicorIce(){
} // end deconstructor

// constructor
LicorIce::LicorIce(int setScore, int setPower, string setName) {
    shatterScore = setScore;
    power = setPower;
    name = setName;
} // end constructor