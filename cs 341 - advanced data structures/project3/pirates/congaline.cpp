#include "congaline.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// default constructor
CongaLine::CongaLine() {
    head = nullptr;
    tail = nullptr;
    barHeight = 10;
    pirateFile.open("portal.txt");

    // fill the list with 20 pirates
    for(int i = 0; i < 20; i++) 
        insertAtTail(getPirate());

    doubleEdgedSword = search(0);

    cout << "initial pirates: " << endl;
    printPirate();
    
    commandFile.open("commands.txt");

    string command = "";
    int number = 0;
    while(commandFile>>command){
        commandFile>>number;
        if(command=="lshift")
            lshift(number);
        else if(command=="rshift")
            rshift(number);
        else if(command=="hammer")
            hammer(number);
        else if(command=="setbar")
            setBarHeight(number);
        else if(command=="tacticalnuke")
            tacticalNuke();
        else if(command=="lowerbar")
            lowerBar();
        else
            cout << "Invalid Commmand." << endl;
    }

    cout << "After commands: " << endl;
    printPirate();

    cout << "Sword is at pirate " << doubleEdgedSword->pirate.name << endl;
    cout << "Bar is at " << getBarHeight() << endl;
}

// destructor
CongaLine::~CongaLine() {
    for(int i = 0; i < 20; i++) 
        deleteAtNode(head);
    pirateFile.close();
    commandFile.close();
}

// core functionality

// For both lshift and rshift, if you are too close to the edge of the array to execute the full shift, do as much as you can and then terminate normally

// moves the double-edged sword to the left and pirates must limbo underneath, inserts replacement pirates at the tail
void CongaLine::lshift(int increment) {
    while(increment!=0){
        if(doubleEdgedSword==head){
            //cout << "Unable to rshift anymore. Deleting if necessary." << endl;
            //doubleEdgedSword->pirate.print();
            //cout << endl;
            if(!doubleEdgedSword->pirate.canLimbo(barHeight)) {
                doubleEdgedSword = doubleEdgedSword->next;
                // doubleEdgedSword->pirate.print();
                // doubleEdgedSword->prev->pirate.print();
                deleteAtNode(doubleEdgedSword->prev);
                insertAtTail(getPirate());
            }
            else{
                doubleEdgedSword->pirate.numLimbos++;
            }
            return;
        }

        //cout << "limbo" << endl;

        // if sword moves over pirate, check if pirate can limbo
        // if cannot, delete pirate and insert new from portal
        if(doubleEdgedSword->pirate.canLimbo(barHeight)) {
            increment--;
            doubleEdgedSword->pirate.numLimbos++;
            doubleEdgedSword = doubleEdgedSword->prev;
        }
            
        else {
            doubleEdgedSword = doubleEdgedSword->prev;
            deleteAtNode(doubleEdgedSword->next);
            increment--;
            insertAtTail(getPirate());
        }
    }
}

// moves the double-edged sword to the right and pirates must limbo underneath, inserts replacement pirates at the head
void CongaLine::rshift(int increment) {
    // cout << "Beginning right shift." << endl;
    // cout << "Bar height: " << getBarHeight() << endl;
    while(increment!=0){
        if(doubleEdgedSword == tail) {
            // cout << "Unable to rshift anymore. Deleting if necessary." << endl;
            if(!doubleEdgedSword->pirate.canLimbo(barHeight)) {
                doubleEdgedSword = doubleEdgedSword->prev;
                deleteAtNode(doubleEdgedSword->next);
                insertAtHead(getPirate());
            }
            else{
                doubleEdgedSword->pirate.numLimbos++;
            }
            return;
        }
        // if sword moves over pirate, check if pirate can limbo
        // if cannot, delete pirate and insert new from portal
        if(doubleEdgedSword->pirate.canLimbo(barHeight)) {
            // cout << doubleEdgedSword->pirate.name <<" saved! " << endl;
            increment--;
            doubleEdgedSword->pirate.numLimbos++;
            doubleEdgedSword = doubleEdgedSword->next;
        }

        else {
            // cout << "***Items in List***: " << length() << endl;
            // cout << doubleEdgedSword->pirate.name << " to be killed :(" << endl;
            doubleEdgedSword = doubleEdgedSword->next;
            //cout << "Going to delete pirate " << doubleEdgedSword->prev->pirate.name << " now..." << endl;
            deleteAtNode(doubleEdgedSword->prev);
            // if(!deleteAtNode(doubleEdgedSword->prev))
            //     cout << "Delete failed." << endl;
            // else
            //     cout << "delete successful" << endl;
            increment--;
            // cout << "***Items in List***: " << length() << endl;
            insertAtHead(getPirate());
            // cout << "***Items in List***: " << length() << endl;
            // cout << endl;
            // printPirate();
            // cout << endl;
        } 
    }
}

// takes an integer value from [0, 20) and deletes the node at that list location, then inserts a new pirate at the tail
void CongaLine::hammer(int destroy) {
    if(destroy >= 20){
        cout << "Invalid hammer value." << endl;
        return;
    }
    deleteAtNode(search(destroy));
    insertAtTail(getPirate());
}

// decrements the value of the bar height by 1, as long as it is positive. If the bar is already 0 when this function is called, set the bar back to 10
void CongaLine::lowerBar() {
    if(barHeight > 0) {
        barHeight--;
    }
    else if(barHeight == 0) {
        barHeight = 10;
    }
    else {
        cout << "error! negative bar height" << endl;
    }
}

// executes hammer(0) 20 times
void CongaLine::tacticalNuke() {
    for(int x = 0; x < 20; x++) {
        hammer(0);
    }
}


// other functions
int CongaLine::length() {
    int length = 0;

    Node * tempNode = head;

    while(tempNode){
        length++;
        tempNode = tempNode->next;
    }
    return length;
}

bool CongaLine::insertAtHead(Pirate addHead) {
    Node * toAdd = new Node(addHead);

    // if the list is empty
    if(!head)
        head = tail = toAdd;

    // if the list has at least 1 item already in it
    else {
        toAdd->next = head;
        head->prev = toAdd;
        head = toAdd;
    }
    //cout << head->pirate.name << " is the head now." << endl;
    return true;
}

bool CongaLine::insertAtTail(Pirate addTail) {
    Node * toAdd = new Node(addTail);

    // if the list is empty
    if(!tail)
        head = tail = toAdd;

    // if the list has at least 1 item already in it
    else {
        tail->next = toAdd;
        toAdd->prev = tail;
        tail = toAdd;
    }
    return true;
}

// takes an integer value i and returns ith element of the list
Node * CongaLine::search(int find) {
    if(!head)
        return nullptr;

    if(find>=20){
        cout << "Conga line only contains 20 pirates." << endl;
        return nullptr;
    }

    Node * currentNode = head;
    for(int x = 0; x < find; x++){
        currentNode = currentNode->next;
    }
    return currentNode;
}

bool CongaLine::deleteAtNode(Node * toDelete) {
    if(!head)
        return false;
    else if(head==tail && toDelete == head){ // Exactly one element using a fancy checking tool. Necessary, no. Tux level awesome, yes.
        delete toDelete;
        head = tail = nullptr;
    }
    else{ // Two or more elements remaining in the list.
        if(toDelete==head){
            head=head->next;
            delete toDelete;
        }
        else if(toDelete==tail){
            tail = toDelete->prev;
            tail->next = toDelete->next;
            delete toDelete;
            
        }
        else{
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
        }
    }
    return true;
}

void CongaLine::printPirate() {
    if(!head)
        cout << "The conga line is empty!" << endl;

    Node * printNode = head; // start with the head (start) of the list

    while(printNode != nullptr) // loop through the whole list
    {
        printNode->pirate.print(); // print out the current node's pirate
        printNode = printNode->next; // move the pointer to the next list item
    }

    cout << "\n";
}

// gets new pirate from the portal
Pirate CongaLine::getPirate() {
    string name = "";
    unsigned int height = 0;
    
    pirateFile >> name >> height;
    return Pirate(name, height);
}