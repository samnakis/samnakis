#include "chaining.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// constructor
HashTableChaining::HashTableChaining() {
    table = new list<int>[tablesize];
    // pushes 0 into the front of the table
    for(int i = 0; i < tablesize; i++)
        table[i].push_front(0);

    // string filename = "items.txt";
    // load(filename);
}

// destructor
HashTableChaining::~HashTableChaining() {
    delete [] table;
}

// start insert
int HashTableChaining::insert(int value) {
    cout << "Attempting to insert " << value << "..." << endl;

    if(search(value) == 1) {
        // value already in table, return 1
        return 1;
    }

    // adds element at the back of our list
    table[value % tablesize].push_back(value);
    cout << "Value successfully inserted into the table!\n" << endl;

    // we will never return 0 because our program is too small and the only case you fail is when you don't have enough memory allocated
    
    return 1;
} // end insert

// start search
int HashTableChaining::search(int value) {
    for (list<int>::iterator x = table[value % tablesize].begin(); x != table[value % tablesize].end(); x++)
        if (*x == value) {
            cout << "Value found in table!\n" << endl;
            return 1;
        }
    cout << "Value not found.\n" << endl;
    return 0;
} // end search

// start remove
int HashTableChaining::remove(int value) {
    for (list<int>::iterator x = table[value % tablesize].begin(); x != table[value % tablesize].end(); x++)
        if (*x == value) {
            x = table[value % tablesize].erase(x);
            cout << "Value successfully removed from table.\n" << endl;
            return 1;
        }
    cout << "Value not deleted.\n" << endl;
    return 0;
}

// start load
int HashTableChaining::load(string file) {
    // deleting any existing table before loading in a new one
    delete [] table;
    ifstream fin;
    fin.open(file);

    // making sure the file exists
    if(!fin) {
        cout << "\nERROR: The file could not be opened!" << endl;
        return 0;
    }
    
    int valadd = 0;
    fin >> tablesize >> numitems;
    table = new list<int>[tablesize];
    while(fin >> valadd) {
        if(insert(valadd))
            cout << "Successfully inserted " << valadd << endl;
        else
            cout << "Unsuccessful insert on " << valadd << endl;
    }
    cout << "\nFile has been loaded and all entries have been inserted into the table!\n" << endl;
    return 1;
}  

// start print
void HashTableChaining::print() {
    cout << "***********************************\n" << endl;
    for(int i = 0; i < tablesize; i++) {
        if(i <= 9)
            cout << "[0" << i << "]: ";
        else
            cout << "[" << i << "]: ";
        for (list<int>::iterator x = table[i].begin(); x != table[i].end(); x++) {
            cout << setw(2) << *x;
            if(*x == table[i].back()) {
                // don't print arrow if you're in the last position of the list in that spot
            }
            else {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    cout << "\n***********************************\n" << endl;
}
// end print