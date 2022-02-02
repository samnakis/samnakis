// CS 351: Project 3
// main.cpp

//Created by Sam Nakis and Maya Sanchez on 12/3/2021

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include <stdlib.h>
#include <time.h>

#include "randoNum.h"
#include "pq.h"

// global variables
int globalTotalItems = 0; // global variable for total number of items
int globalCapacity = 0; // global variable for capacity

int maxValue = 0; // maximum value so far

int currWeight = 0; // current weight in the knapsack
int currValue = 0; // current value in the knapsack

// these functions were created using the psuedocode from the book

// promising function declaration
bool promising(int index, Item items[], int currValue, int currWeight);

// knapsack function using backtracking algorithm
void knapsackF(int index, int currValue, int currWeight, int globalCapacity, Item items[], bool include[], bool bestset[]) {
	if(currWeight <= globalCapacity && currValue > maxValue) {
		maxValue = currValue; 
		for(int i = 0; i <= globalTotalItems; i++) {
			bestset[i] = include[i];
		}
	}
	
	if(promising(index, items, currValue, currWeight)) {
		include[index] = true;

		knapsackF(index+1, currValue + items[index+1].value, currWeight+items[index+1].weight, globalCapacity, items, include, bestset);

		include[index] = false;

		knapsackF(index+1, currValue, currWeight, globalCapacity, items, include, bestset);

	}
} // end knapsack function

// start promising function
bool promising(int index, Item items[], int currValue, int currWeight) {
	int j;
	int k;
	j = index;
	k = index;

	int totWeight;
	float bound;

	if(currWeight >= globalCapacity) {
		return false;
	}
	else {
		j = index + 1;
		bound = currValue;
		totWeight = currWeight;
		while((j <= globalTotalItems) && ((totWeight + items[j].weight) <= globalCapacity)) {
			totWeight += items[j].weight;
			bound += items[j].value;
			j++;
		}
		k = j;
		if(k <= globalTotalItems) {
			bound += (float)(globalCapacity - totWeight) * ((float)items[k].value/(float)items[k].weight);
		}

		return bound > maxValue;
	}
} // end promising function


int main() {
	srand(time(0));
	// using priority queue
	typedef pq<Item> ItemPQ;
    ItemPQ knapsackQueue = ItemPQ();
	ItemPQ knapsack = ItemPQ();
    Item currentItem = Item();

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

	// setting inputs to global variables we can use in the functions above the main
	globalTotalItems = totalItems;
	globalCapacity = capacity;

	// new arrays
	// set to totalItems + 1 because we made an empty filler item
	bool include[totalItems+1];
	bool bestset[totalItems+1];
	Item items[totalItems+1];

	// filling include and bestset
	for(int i = 0; i <= totalItems; i ++) {
        include[i] = 0;
    }

	for(int i = 0; i <= totalItems; i ++) {
        bestset[i] = 0;
    }

	// fills the priority queue
    for(int x = 0; x < totalItems; x++) {
        inFile >> name >> value >> weight;

        Item toAdd = Item(value, weight, name);

        knapsackQueue.enqueue(toAdd);
    }

	// filler item
	items[0] = Item(0, 0, "sad");

	// sorting
	for(int x = 1; x <= totalItems; x++) {
		items[x] = knapsackQueue.dequeue();
	}

	// for(int x =1; x <= totalItems; x++) {
	// 	items[x].print();
	// }

	// calling knapsack function
	knapsackF(0, 0, 0, capacity, items, include, bestset);

	// OUTPUT
    int itemsInSol = 0;
    int totalWeight = 0;
    int totalValue = 0;

	int W = 0;

	int count = 0;
	int count1 = 0;

    cout << "\n!! Output" << endl;
    cout << "Items in the Solution:" << endl;
	cout << "Format: name value weight" << endl;
    for (int i = 0; i < totalItems; i++)
    {
        if (bestset[i] == true) {
            cout << items[i+1].name << " " << items[i+1].value << " " << items[i+1].weight << endl;
            totalWeight += items[i+1].weight;
            totalValue += items[i+1].value;
            W += items[i+1].weight;
            count++;
        }
    }

	cout << "\nNumber of items in the solution: " << count << endl;
    cout << "Overall value of selected items: " << totalValue << endl;
    cout << "Overall weight of selected items: " << totalWeight << endl;
    cout << "Maximum weight possible: " << capacity << endl << endl;

    inFile.close();

	return 0;
}

