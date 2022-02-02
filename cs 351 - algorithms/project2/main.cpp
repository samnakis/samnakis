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

int maximum(int oldValue, int newValue) {
    if(newValue > oldValue)
        return newValue;
    else
        return oldValue;
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

	// fill column and row if weight or capacity is 0
	for (int x = 0; x < totalItems + 1; x++)
    {
        itemMatrix[x][0] = 0;
        choiceMatrix[x][0] = false;
    }

    for (int x = 0; x < capacity+1; x++)
    {
        itemMatrix[0][x] = 0;
        choiceMatrix[0][x] = false;
    }

	for (int i = 1; i <= totalItems; i++) {
		for (int j = 1; j <= capacity; j++) {
			// if wi > w
			// P[i-1][w]
			if(itemList[i - 1].weight > j) {
                itemMatrix[i][j] = itemMatrix[i-1][j];
                choiceMatrix[i][j] = false;
            }
			// if wi <= w
			// maximum P[i-1][w], pi+P[i-1][w-wi]
            else {
                itemMatrix[i][j] = maximum((itemMatrix[i - 1][j]), (itemList[i-1].value + itemMatrix[i - 1][(int)(j - itemList[i-1].weight)])); 
                if (itemMatrix[i][j] == (itemList[i-1].value + itemMatrix[i - 1][(int)(j - itemList[i-1].weight)]))
                    choiceMatrix[i][j] = true;
                else
                    choiceMatrix[i][j] = false;
            }
		}
	}

	// // printing matrix
	// cout << "matrix: " << endl;
	// for (int i = 0; i < totalItems+1; i++) {
    //     for (int w = 0; w < capacity+1; w++) {
    //         cout << setw(3) << itemMatrix[i][w];
    //     }
    //     cout << "\n" << endl;
    // }

	// // printing choice matrix
	// cout << "\n" << "choice matrix: " << endl;
	// for (int i = 0; i < totalItems+1; i++) {
    //     for (int w = 0; w < capacity+1; w++) {
    //         cout << setw(3) << choiceMatrix[i][w];
    //     }
    //     cout << "\n" << endl;
    // }

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