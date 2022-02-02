#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    int n = 0;
    unsigned int w = 0;
    cout << "How many pirates would you like to create? ";
    cin >> n;

    cout << "What would you like the height to be capped at? ";
    cin >> w;

    ofstream fout;
    fout.open("portal.txt");
    for(int x = 0; x < n; x++){
        fout << setfill('0') << "pirate" << setw(3) << to_string(x) << " " << rand() % w + 1 << endl; 
    }
   
    return 0;
}