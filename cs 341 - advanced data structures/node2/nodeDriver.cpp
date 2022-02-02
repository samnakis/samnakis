// #include "node.h"
#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
    /* OLD VERSION
    Node * newNode1 = new Node();
    Node * newNode2 = new Node();
    Node * newNode3 = new Node();
    Node * newNode4 = new Node();

    // setting up list, have item in x spot point to the next spot in the list
    newNode1->item = "milk";
    newNode1->next = newNode2;

    newNode2->item = "bread";
    newNode2->next = newNode3;

    newNode3->item = "eggs";
    newNode3->next = newNode4;

    newNode4->item = "cereal";

    // Node * printNode = newNode1;
    // while(printNode != nullptr) {
    //     cout << printNode->item << endl;
    //     printNode = printNode->next;
    // }

    delete newNode1;
    delete newNode2;
    delete newNode3;
    delete newNode4;
    */

    // LINKED LIST VERSION
    LinkedList * groceryList = new LinkedList();

    groceryList->insertNode("milk");
    groceryList->insertNode("bread");
    groceryList->insertNode("eggs");
    groceryList->insertNode("cereal");

    groceryList->printList();

    Node * foundNode = groceryList->search("bread");
    cout << "found node: " << foundNode->item << endl;

    bool empty = groceryList->isEmpty();
    if(empty == true) {
        cout << "your list is empty!" << endl;
    }
    else {
        int listSize = groceryList->length();
        cout << "list is " << listSize << " items long" << endl;
    }

    return 0;
}