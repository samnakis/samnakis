// CS 351: Project 2
// main.cpp

//Created by Sam Nakis and Maya Sanchez on 11/5/2021

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include <stdlib.h>
#include <time.h>

#include "randoNum.h"
#include "item.h"

int main()
{
	srand(time(0));

	int totalItems = 0;
	int capacity = 0;

	string name = "";
	int value = 0;
	int weight = 0;

	// // To create & open file(s)
	// ofstream outFile;
	// outFile.open("niceFile.txt");
	// if (!outFile)
	// {
	// 	cerr << "ERROR: The final could not be opened!" << endl;
	// 	exit(1);
	// }

	// // Print for user to input items and capacity for Knapsack
	// cout << "Please input the number of items you want: ";
	// cin >> totalItems;

	// cout << "Please input the capacity of your knapsack: ";
	// cin >> capacity;

	// makeTextFile(totalItems, capacity);

	// outFile.close();

	// Input stream class to operate on files
	ifstream inFile;
	inFile.open("niceFile.txt");

	inFile >> totalItems;
	inFile >> capacity;


	// making item array and reading in
	Item itemList[totalItems];

	cout << "item list: " << endl;
	for(int i = 0; i < totalItems; i++) {
		inFile >> name >> value >> weight;
		itemList[i] = Item(value, weight, name);
		// testing
		itemList[i].print();
	}
	cout << endl;

	int itemMatrix[totalItems+1][capacity+1];
	bool choiceMatrix[totalItems+1][capacity+1];

	for(int i = 0; i < totalItems+1; i++) {
		for(int w = 0; w < capacity+1; w++) {
			// fill column and row if weight or capacity is 0
			if(i == 0 || w == 0) {
				itemMatrix[i][w] = 0;
				choiceMatrix[i][w] = false;
			}
			// if wi <= w
			// maximum P[i-1][w], pi+P[i-1][w-wi]
			else if(itemList[i].weight <= w) {
				if(itemMatrix[i-1][w] > itemList[i].value + itemMatrix[i-1][w-itemList[i].weight]) {
					itemMatrix[i][w] = itemMatrix[i-1][w];
					choiceMatrix[i][w] = false;
				}
				else {
					itemMatrix[i][w] = itemList[i].value + itemMatrix[i-1][w-itemList[i].weight];
					choiceMatrix[i][w] = true;
				}
			}
			// if wi > w
			// P[i-1][w]
			else {
				itemMatrix[i][w] = itemMatrix[i-1][w];
				choiceMatrix[i][w] = false;
			}
		}
	}

	// printing matrix
	cout << "matrix: " << endl;
	for (int i = 0; i < totalItems+1; i++) {
        for (int w = 0; w < capacity+1; w++) {
            cout << setw(3) << itemMatrix[i][w];
        }
        cout << "\n" << endl;
    }

	cout << "\n" << "choice matrix: " << endl;
	for (int i = 0; i < totalItems+1; i++) {
        for (int w = 0; w < capacity+1; w++) {
            cout << setw(3) << choiceMatrix[i][w];
        }
        cout << "\n" << endl;
    }

	return 0;
}