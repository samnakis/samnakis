#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    int n = 1001;
    int s = 10001;
    int p = 101;
    
    while(n>=1000){
        cout << "How many IceBabys would you like to create? ";
        cout << "You will be asked this question again if you enter a number greater than 1000." << endl;
        cin >> n;
    }

    while(s>=10000){
        cout << "What would you like the shatterScore to be capped at? ";
        cout << "You will be asked this question again if you enter a number greater than 10000." << endl;
        cin >> s;
    }

    while(p>=100){
        cout << "What would you like the power to be capped at? ";
        cout << "You will be asked this question again if you enter a number greater than 100." << endl;
        cin >> p;
    }

    ofstream fout;
    fout.open("bbfile.txt");
    for(int x = 0; x < n; x++){
        fout << setfill('0') << "icebaby" << setw(3) << to_string(x) << " " << rand() % s + 1 << " " << rand() % p + 1  << endl; 
    }
   
    return 0;
}