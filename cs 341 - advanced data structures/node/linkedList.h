#include "node.h"
#include <string>
using namespace std;

class LinkedList {
    public:
        Node * head;
        Node * tail;

        LinkedList();
        ~LinkedList();

        void printList();
        void insertNode(string itemToAdd);
        bool isEmpty();
        int length();
        Node * search(string itemToFind);
};