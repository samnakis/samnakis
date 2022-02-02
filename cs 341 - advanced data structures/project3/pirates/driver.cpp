#include "pirate.h"
#include "node.h"
#include "congaline.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    CongaLine * line = new CongaLine();
    
    // cout << "Round 1: " << line->getBarHeight() << endl;
    // line->rshift(23);
    // line->printPirate();

    // line->lowerBar();

    // cout << "Round 2: " << line->getBarHeight() << endl;
    // line->lshift(23);
    // line->printPirate();

    // line->lowerBar();

    // cout << "Round 3: " << line->getBarHeight() << endl;
    // line->rshift(23);
    // line->printPirate();

    // cout << "Hammer Time!" << endl << endl;
    // cout << "Hammer 3:" << endl;
    // line->hammer(3);
    // line->printPirate();
    // cout << endl;

    // cout << "Hammer 15:" << endl;
    // line->hammer(15);
    // line->printPirate();
    // cout << endl;

    // cout << "Nuke:" << endl;
    // line->tacticalNuke();
    // line->printPirate();
    // cout << endl;

    delete line;

    return 0;
}
