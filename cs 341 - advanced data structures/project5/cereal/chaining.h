#include "hashtable.h"
#include <list>

// start class HashTableChaining
class HashTableChaining {
    public:
        HashTableChaining();
        ~HashTableChaining();

        list<int> * table;
        int tablesize = 10;
        int numitems = 0;

        virtual int insert(int value);
        virtual int search(int value);
        virtual int remove(int value);
        virtual int load(string file);     
        virtual void print();
    
}; // end class HashTableChaining