#include "pirate.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

// moved from pirate.h
int Pirate::numDead = 0;

// default constructor
Pirate::Pirate() {
    name = "";
    height = 0;
    numLimbos = 0;
    numDead = 0;
} // end default constructor

// destructor
Pirate::~Pirate() {
    
} // end destructor

// constructor
Pirate::Pirate(string setName, unsigned int setHeight) {
    name = setName;
    height = setHeight;
    numLimbos = 0;
    numDead = 0;
} // end constructor