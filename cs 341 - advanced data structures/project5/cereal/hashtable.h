#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

// This is defined as a pure virtual class, since no implementations are provided the majority
// of the functions, you MUST write implementations for them in all derived classes.
// As a reminder, a pure virtual function (one that must be redefined) has an "= 0" at the end of it.

class HashTable {
    private:
        int m;                                  // Size of the internal table(s)
        
	public:
		// Class setup
		HashTable() {};
        virtual ~HashTable() {};
		
		// Core functionality
		virtual int insert(int value) = 0;      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
        virtual int search(int value) = 0;      // Returns 1 if the entry was in the table, 0 otherwise.
        virtual int remove(int value) = 0;      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.
        virtual int load(string file) = 0;      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                                // You may assume that input files do not cause inserts that return 0.
        virtual void print() = 0;               // Print the table in a pretty way that is useful to look at. You will need to use your iomanip-fu to make this beautiful. Be ready.
        
}; // end class HashTable

#endif