#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    int tablesize = 10000;
    int numitems = 100000;

    while(tablesize>1000) {
        cout << "How big would you like to make your table? You will be asked to enter again if your table is 1000 or bigger.";
        cin >> tablesize;
    }

    while(numitems>1000) {
        cout << "How many items would you like to create? You will be asked to enter again if your table is 1000 or bigger.";
        cin >> numitems;
    }

    ofstream fout;
    fout.open("items.txt");
    fout << tablesize << endl; 
    fout << numitems << endl;
    for(int x = 1; x <= numitems; x++){
        fout << setfill('0') << to_string(x) << endl; 
    }
   
    return 0;
}