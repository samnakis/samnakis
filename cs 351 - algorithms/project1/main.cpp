// CS 351: Project 1
//main.cpp

//Created by Sam Nakis and Maya Sanchez on 10/12/2021

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "pq.h"
#include "randoNum.h"

int main()
{
	srand(time(0));

	// Include enqueue &dequeue
	typedef pq<Item> ItemPQ;
	ItemPQ knapsackQueue = ItemPQ();
	ItemPQ knapsack = ItemPQ();
	Item currentItem = Item();

	int totalItems = 0;
	int capacity = 0;

	string name = "";
	int value = 0;
	int weight = 0;

	int itemsInSol = 0;
	int totalWeight = 0;
	int totalValue = 0;

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

	// Fills the priority queue
	for (int x = 0; x < totalItems; x++)
	{
		inFile >> name >> value >> weight;

		Item toAdd = Item(weight, value, name);

		knapsackQueue.enqueue(toAdd);
	}

	for (int x = totalItems; x > 0; x--)
	{
		// copy constructor being used here
		currentItem = knapsackQueue.dequeue();

		if (currentItem.weight <= capacity)
		{
			knapsack.enqueue(currentItem);
			capacity -= currentItem.weight;
			itemsInSol++;
			totalWeight += currentItem.weight;
			totalValue += currentItem.value;
		}
	}

	// print final output
	cout << endl << "!! Output: " << endl;
	cout << itemsInSol << endl;
	cout << totalWeight << endl;
	cout << totalValue << endl << endl;
	cout << "Items in the Solution: " << endl;
	for (int x = 0; x < itemsInSol; x++)
	{
		currentItem = knapsack.dequeue();
		currentItem.print();
	}

	inFile.close();

	return 0;
}