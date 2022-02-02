#include "node.h"
#include <string>
using namespace std;

class LinkedList {
    public:
        // head and tail pointer that maintain beginning and end for us
        Node * head;
        Node * tail;

        // default constructor/destructor
        LinkedList();
        ~LinkedList();

        // access functions
        void printList();
        bool isEmpty();
        int length();

        // core functionality
        void insertNode(string itemToAdd); // insert at the tail
        void insertNode(Node *, string itemToAdd); // insert after the node * given (assume input is in the list)
        void deleteNode(Node *); // delete the node * that is pointed to

        Node * search(string itemToFind);
};