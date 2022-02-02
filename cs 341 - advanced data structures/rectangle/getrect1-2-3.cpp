#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

#include "rectangle.cpp"
#include "square.cpp"

int main() {
    // driver program area
    
    //fstream is a class that manages file i/o. it contains three classes: fstream, ifstream, and ofstream

    ifstream fin;
    fin.open("shapearray.txt");

    ofstream fout;
    fout.open("prettyoutput.txt");

    int asize
    fin >> asize;

    int tempw, temph;
    Rectangle * rectarray = new Rectangle[asize];
    for (int x = 0; x < asize; x++)
        fin >> tempw >> temph;
        rectarray[x].setw(tempw);
        rectarray[x].seth(temph);

    for(int x = 0; x < asize; x++)
        rectarray[x].print();

    return 0;
}