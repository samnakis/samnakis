#include "linkedList.h"
#include <iostream>

using namespace std;

// in the default constructor we want to make sure to set the list to be empty by default, so here we set both the head and tail to null which means the list is empty
LinkedList::LinkedList() {
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
}

// destructor is not implemented and therefore the code has memory leaks in it
LinkedList::~LinkedList() {

}

void LinkedList::printList() {
    Node * printNode = head; // start with the head (start) of the list

    while(printNode != nullptr) // loop through the whole list
    {
        cout << printNode->item << endl; // print out the current nodes item
        printNode = printNode->next; // move the pointer to the next list item
    }

    cout << "\n";
}

void LinkedList::insertNode(string itemToAdd) { // insert new nodes onto the end of the list
    Node * newNode = new Node(); // create a new blank node to add
    newNode->item = itemToAdd; // set the new nodes item to whatever was passed in by the user

    if(head == nullptr) { // if the list is empty
        // set out new node to be the head and tail of the list (the first and only item)
        head = newNode;
        tail = newNode;
    }

    else { // the list has at least 1 item already in it
        tail->next = newNode; // set the current tails next pointer to our new node
        tail = newNode; // make our new node the new tail of the list
    }
}

bool LinkedList::isEmpty() {
    if(head == nullptr) { // if the head is null the list is empty
        return true;
    }
    return false;
}

// note: there is a different and probably better way to do this
// 1. create a local size variable that will hold how big the list is
// 2. update this variable anytime you add or delete to the list
// 3. in this method simply return the size variable
int LinkedList::length() {
    int count = 0;
    Node * iterator = head; // start with the head

    while(iterator != nullptr) { // loop through the whole list
        count++; // increase our count variable
        iterator = iterator->next; // move to the next node in the list
    }

    return count; // return the full calculated count at the end
}

Node * LinkedList::search(string itemToFind) {
    if(head == nullptr) { // check if the list is empty
        return nullptr; // if it is the user will not find what they are looking for so return null back to them
    }
    else {
        Node * currentNode = head; // start with the head
        while(currentNode != nullptr) { // loop through the whole list
            if(currentNode->item == itemToFind) { // if our current nodes item is the thing we are looking for
                return currentNode; // return the current node because we found what we were searching for
            }
            else { // if the current nodes item doesn't match what we are looking for
                currentNode = currentNode->next; // move the current node to the next node in the list
            }
        }
        return nullptr; // if we get this far that means we went through the whole list and didn't find what we were looking for so return null back
    }
}
