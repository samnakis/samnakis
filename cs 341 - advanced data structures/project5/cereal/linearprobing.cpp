#include "linearprobing.h"
#include <iostream>
#include <fstream>
using namespace std;

// constructor
HashTableLinearProbing::HashTableLinearProbing() {
    table = new int[tablesize];
    for(int i = 0; i < tablesize; i++)
        table[i] = 0;

    // string filename = "items.txt";
    // load(filename);
}

// destructor
HashTableLinearProbing::~HashTableLinearProbing() {
    delete [] table;
}

// start insert
int HashTableLinearProbing::insert(int value) {
    cout << "Attempting to insert " << value << "..." << endl;

    if(search(value) == 1) {
        // value already in table, return 1
        return 1;
    }

    for(int x = value % tablesize; x != (value - 1) % tablesize; x = (x+1)%tablesize) {
        if(!table[x]) {
            table[x] = value;
            cout << "Value successfully inserted into the table!\n" << endl;
            return 1;
        }
    }
    cout << "Value not inserted.\n" << endl;
    return 0;
} // end insert

// start search
int HashTableLinearProbing::search(int value) {
    // Start with a dumb search, room for optimization.
    for(int x = value % tablesize; x != (value - 1) % tablesize; x = (x+1)%tablesize)
        if(table[x] == value)
        {
            cout << "Value found in table!\n" << endl;
            return 1;
        }
    cout << "Value not found.\n" << endl;
    return 0;
} // end search

// start remove
int HashTableLinearProbing::remove(int value) {
    // similar to search function
    for(int x = value % tablesize; x != (value - 1) % tablesize; x = (x+1)%tablesize)
        if(table[x] == value) {
            table[x] = 0;
            cout << "Value successfully removed from table.\n" << endl;
            return 1;
        }
    cout << "Value not deleted.\n" << endl;
    return 0;
} // end remove

// start load
int HashTableLinearProbing::load(string file) {
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
    table = new int[tablesize];
    while(fin >> valadd) {
        if(insert(valadd))
            cout << "Successfully inserted " << valadd << endl;
        else
            cout << "Unsuccessful insert on " << valadd << endl;
    }
    cout << "\nFile has been loaded and all entries have been inserted into the table!\n" << endl;
    return 1;
} // end load

// start print
void HashTableLinearProbing::print() {
    cout << "***********************************\n" << endl;
    for(int i = 0; i < tablesize; i++) {
        if(i <= 9) 
            cout << "[0" << i << "]: " << table[i] << endl;
        else
            cout << "[" << i << "]: " << table[i] << endl;
    }
    cout << "\n***********************************\n" << endl;
} // end print