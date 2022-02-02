#include "hashtable.h"

// start class HashTableCuckoo
class HashTableCuckoo {
    public:
        HashTableCuckoo();
        ~HashTableCuckoo();

        int * table1;
        int * table2;
        int inputsize = 10;
        int tablesize = 5;
        int numitems = 0;
        int loopnum = 0;

        virtual int insert(int value);
        int reinsert(int value);
        virtual int search(int value);
        virtual int remove(int value);
        virtual int load(string file);     
        virtual void print();
    
}; // end class HashTableCuckoo