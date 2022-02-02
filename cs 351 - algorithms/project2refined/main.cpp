// CS 351: Project 2
// main.cpp

// Created by Sam Nakis and Maya Sanchez on 11/5/2021

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include <stdlib.h>
#include <time.h>

#include "randoNum.h"
#include "item.h"

int maximum(int oldValue, int newValue) {
    if(newValue > oldValue)
        return newValue;
    else
        return oldValue;
}

int baguette(int rowsize, int colsize, int** a, bool** s, Item array[]) {
	// base case
	// outer rows and columns are 0
	if(rowsize == 0 || colsize == 0) {
		a[rowsize][colsize] = 0;
		s[rowsize][colsize] = false;
		return 0;
	}

	// recurion!
	int maxOption1 = baguette(rowsize-1, colsize, a, s, array);
	int maxOption2 = array[rowsize].value + baguette(rowsize-1, colsize-array[colsize].weight, a, s, array);

	int maxVal = 0;

	// if wn > W
	if(colsize > array[colsize].weight) {
		maxVal = a[rowsize-1][colsize];
		a[rowsize][colsize] = maxVal;
		s[rowsize][colsize] = false;
	}

	// if wn <= W
	else {
		maxVal = maximum(maxOption1, maxOption2);
		a[rowsize][colsize] = maxVal;
		s[rowsize][colsize] = true;
	}

	return maxVal;
}


int main()
{
	srand(time(0));

	int totalItems = 0;
	int capacity = 0;

	string name = "";
	int value = 0;
	int weight = 0;

	// To create & open file(s)
	ofstream outFile;
	outFile.open("niceFile.txt");
	if (!outFile)
	{
		cerr << "ERROR: The final could not be opened!" << endl;
		exit(1);
	}

	// Print for user to input items and capacity for Knapsack
	cout << "Please input the number of items you want: ";
	cin >> totalItems;

	cout << "Please input the capacity of your knapsack: ";
	cin >> capacity;

	makeTextFile(totalItems, capacity);

	outFile.close();

	// Input stream class to operate on files
	ifstream inFile;
	inFile.open("niceFile.txt");

	inFile >> totalItems;
	inFile >> capacity;


	// making item array and reading in
	// Item itemList[totalItems];
	Item* itemList = new Item[totalItems];

	// cout << "item list: " << endl;
	for(int i = 0; i < totalItems; i++) {
		inFile >> name >> value >> weight;
		itemList[i] = Item(value, weight, name);
		// testing
		// itemList[i].print();
	}
	cout << endl;

	int itemMatrix[totalItems+1][capacity+1];
	bool choiceMatrix[totalItems+1][capacity+1];

	// function call
	baguette(totalItems, capacity, itemMatrix, choiceMatrix, itemList);


	// printing matrix
	cout << "matrix: " << endl;
	for (int i = 0; i < totalItems+1; i++) {
        for (int w = 0; w < capacity+1; w++) {
            cout << setw(3) << itemMatrix[i][w];
        }
        cout << "\n" << endl;
    }

	// printing choice matrix
	cout << "\n" << "choice matrix: " << endl;
	for (int i = 0; i < totalItems+1; i++) {
        for (int w = 0; w < capacity+1; w++) {
            cout << setw(3) << choiceMatrix[i][w];
        }
        cout << "\n" << endl;
    }

	// output
    int size = capacity;
    int totalWeight = 0;
    int totalProfit = 0;
    int count = 0;

    cout << "\n!! Output:" << endl;
    cout << "Items in the Solution:" << endl;
    for (int i = 0; i < totalItems; i++) {
        if (choiceMatrix[i+1][size] == true) {
            cout << itemList[i].name << " " << itemList[i].value << " " << itemList[i].weight << endl;
            totalWeight += itemList[i].weight;
            totalProfit += itemList[i].value;
            size = size - itemList[i].weight;
            count++;
        }
    }

    cout << "\nNumber of items in the solution: " << count << endl;
    cout << "Overall value of selected items: " << totalProfit << endl;
    cout << "Overall weight of selected items: " << totalWeight << endl;
    cout << "Maximum weight possible: " << capacity << endl << endl;
    // end output

	return 0;
}