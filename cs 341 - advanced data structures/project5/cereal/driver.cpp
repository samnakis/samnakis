#include <fstream>
#include <iostream>
#include "linearprobing.h"
#include "chaining.h"
#include "cuckoo.h"
using namespace std;

// function to print primary menu
void primaryMenu() {
    cout << "Here is a list of commands: " << endl;
    cout << endl;
    cout <<	"1) Linear Probing" << endl;
    cout <<	"2) Separate Chaining" << endl;
    cout <<	"3) Cuckoo Hashing" << endl;
    cout <<	"0) Quit" << endl;
    cout << endl;
}

// function to print secondary menu bc we're good coders <3
void secondaryMenu() {
    cout <<	"1) Load table from file" << endl;
    cout <<	"2) Insert" << endl;
    cout <<	"3) Search" << endl;
    cout <<	"4) Delete" << endl;
    cout <<	"5) Print Hash Table" << endl;
    cout <<	"0) Quit" << endl;
}

int main() {
    int primaryCommand = 0;
    int secondaryCommand = 0;
    int insertval = 0;
    int searchval = 0;
    int removeval = 0;
    string file = "";
    HashTableLinearProbing table1;
    HashTableChaining table2;
    HashTableCuckoo table3;
	
    // makes sure the program will run at least once and keep running until the user quits
	do {
        cout << "\nWelcome to the Anglo-Saxon Castle!" << endl;
		cout << endl;
		primaryMenu();
		
		cout << "Enter a command: ";
		cin >> primaryCommand;
		cout << endl;
	
		if(primaryCommand == 1)
		{
            do {
                secondaryMenu();
                cout << "\nEnter a command: ";
                cin >> secondaryCommand;
                cout << endl;
                if(secondaryCommand == 1) {
                    cout << "Enter the name of the file you would like";
                    cout << " to load from: ";
                    cin >> file;
                    cout << endl;
                    table1.load(file);
                }
                else if(secondaryCommand == 2) {
                    cout << "Enter the value you would like to insert: ";
                    cin >> insertval;
                    cout << endl;
                    table1.insert(insertval);
                }
                else if(secondaryCommand == 3) {
                    cout << "Enter the value you would like to search: ";
                    cin >> searchval;
                    cout << endl;
                    table1.search(searchval);
                }
                else if(secondaryCommand == 4) {
                    cout << "Enter the value you would like to remove: ";
                    cin >> removeval;
                    cout << endl;
                    table1.remove(removeval);
                }
                else if(secondaryCommand == 5)
                    table1.print();
            } while(secondaryCommand != 0);
		}
			
		if(primaryCommand == 2)
		{
			do {
                secondaryMenu();
                cout << "\nEnter a command: ";
                cin >> secondaryCommand;
                cout << endl;
                if(secondaryCommand == 1) {
                    cout << "Enter the name of the file you would like";
                    cout << " to load from: ";
                    cin >> file;
                    cout << endl;
                    table2.load(file);
                }
                else if(secondaryCommand == 2) {
                    cout << "Enter the value you would like to insert: ";
                    cin >> insertval;
                    cout << endl;
                    table2.insert(insertval);
                }
                else if(secondaryCommand == 3) {
                    cout << "Enter the value you would like to search: ";
                    cin >> searchval;
                    cout << endl;
                    table2.search(searchval);
                }
                else if(secondaryCommand == 4) {
                    cout << "Enter the value you would like to remove: ";
                    cin >> removeval;
                    cout << endl;
                    table2.remove(removeval);
                }
                else if(secondaryCommand == 5)
                    table2.print();
            } while(secondaryCommand != 0);
		}
			
		if(primaryCommand == 3)
		{
			do {
                secondaryMenu();
                cout << "\nEnter a command: ";
                cin >> secondaryCommand;
                cout << endl;
                if(secondaryCommand == 1) {
                    cout << "Enter the name of the file you would like";
                    cout << " to load from: ";
                    cin >> file;
                    cout << endl;
                    table3.load(file);
                }
                else if(secondaryCommand == 2) {
                    cout << "Enter the value you would like to insert: ";
                    cin >> insertval;
                    cout << endl;
                    table3.insert(insertval);
                }
                else if(secondaryCommand == 3) {
                    cout << "Enter the value you would like to search: ";
                    cin >> searchval;
                    cout << endl;
                    table3.search(searchval);
                }
                else if(secondaryCommand == 4) {
                    cout << "Enter the value you would like to remove: ";
                    cin >> removeval;
                    cout << endl;
                    table3.remove(removeval);
                }
                else if(secondaryCommand == 5)
                    table3.print();
            } while(secondaryCommand != 0);
		}	
		
	} while(primaryCommand != 0);
    
    return 0;
}
