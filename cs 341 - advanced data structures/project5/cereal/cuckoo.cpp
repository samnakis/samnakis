#include "cuckoo.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// constructor
HashTableCuckoo::HashTableCuckoo() {
    table1 = new int[tablesize];
    for(int i = 0; i < tablesize; i++)
        table1[i] = 0;
    
    table2 = new int[tablesize];
    for(int i = 0; i < tablesize; i++)
        table2[i] = 0;
}

// destructor
HashTableCuckoo::~HashTableCuckoo() {
    delete [] table1;
    delete [] table2;
}

// start insert
int HashTableCuckoo::insert(int value) {
    cout << "Attempting to insert " << value << "..." << endl << endl;
    int tablenum = 1;
    int maxloop = 0;
    int hashval = 0;

    if(search(value) == 1) {
        // value already in table, return 1
        return 1;
    }
    
    while(maxloop < 20) {
        if(tablenum == 1) {
            hashval = value % tablesize;
            if(!table1[hashval]) {
                table1[hashval] = value;
                cout << "\nValue successfully inserted into table 1!\n" << endl;
                return 1;
            }
            else {
                int holder = table1[hashval];
                table1[hashval] = value;
                value = holder;
                tablenum = 2;
            }
        }
        else if(tablenum == 2) {
            hashval = (value/tablesize) % tablesize;
            if(!table2[hashval]) {
                table2[hashval] = value;
                cout << "\nValue successfully inserted into table 2!\n" << endl;
                return 1;
            }
            else {
                int holder = table2[hashval];
                table2[hashval] = value;
                value = holder;
                tablenum = 1;
            }
        }
        cout << "Looping..." << endl;
        maxloop++;
    }

    // rehash
    cout << "\nMaxloop reached. Value kicked out: " << value << endl << endl;
    cout << "Rehashing..." << endl;
    tablesize += 3;
    int * table3 = table1;
    int * table4 = table2;
    table1 = new int[tablesize];
    table2 = new int[tablesize];

    for(int x = 0; x < tablesize-3; x++) {
        if(insert(table3[x]))
            cout << "\tSuccessfully rehashed " << table3[x] << endl << endl;
        else {
            cout << "\tUnsuccessfully rehashed " << table3[x] << ". Exiting." << endl << endl;
            return 0;
        }
        if(insert(table4[x]))
            cout << "\tSuccessfully rehashed " << table4[x] << endl << endl;
        else {
            cout << "\tUnsuccessfully rehashed " << table4[x] << ". Exiting." << endl << endl;
            return 0;
        }
    }

    delete table3;
    delete table4;
    return 1;
} // end insert

// start search
int HashTableCuckoo::search(int value) {
    // Start with a dumb search, room for optimization.
    if(table1[value % tablesize] == value) {
        cout << "Value found in table 1!\n" << endl;
        return 1;
    }
    if(table2[(value/tablesize) % tablesize] == value) {
        cout << "Value found in table 2!\n" << endl;
        return 1;
    }
    cout << "Value not found.\n" << endl;
    return 0;
} // end search

// start remove
int HashTableCuckoo::remove(int value) {
    // similar to search function
    if(table1[value % tablesize] == value) {
        table1[value % tablesize] = 0;
        cout << "Value successfully removed from table 1.\n" << endl;
        return 1;
    }
    if(table2[(value/tablesize) % tablesize] == value) {
        table2[(value/tablesize) % tablesize] = 0;
        cout << "Value successfully removed from table 2.\n" << endl;
        return 1;
    }
    cout << "Value not deleted.\n" << endl;
    return 0;
} // end remove

// start load
int HashTableCuckoo::load(string file) {
    // deleting any existing table before loading in a new one
    delete [] table1;
    delete [] table2;
    ifstream fin;
    fin.open(file);

    // making sure the file exists
    if(!fin) {
        cout << "\nERROR: The file could not be opened!" << endl;
        return 0;
    }

    int valadd = 0;
    fin >> inputsize >> numitems;
    
    // since we split into two tables, we have an input size and the table size half of that for cuckoo
    tablesize = inputsize/2;
    table1 = new int[tablesize];
    table2 = new int[tablesize];
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
void HashTableCuckoo::print() {
    cout << "***********************************\n" << endl;
    for(int i = 0; i < tablesize; i++) {
        if(i <= 9) 
            cout << "[0" << i << "]: " << setw(2) << table1[i] << setw(15) << "[0" << i << "]: " << setw(2) << table2[i] << endl;
        else
            cout << "[" << i << "]: " << setw(2) << table1[i] << setw(14) << "[" << i << "]: " << setw(2) << table2[i] << endl;
    }
    cout << "\n***********************************\n" << endl;
} // end print