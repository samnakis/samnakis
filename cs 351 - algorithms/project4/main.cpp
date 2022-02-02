// CS 351: Project 4 
// main.cpp

// Created by Sam Nakis and Maya Sanchez on 12/15/2021
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "randoNum.h"
#include "pq.h"
#include "node.h"

// global variables
int globalTotalItems = 0;	// global variable for total number of items
int globalCapacity = 0;	// global variable for capacity

float bound(BNode n, Item items[]);

// created using pseudocode from book
// knapsack function using branch and bound algorithm
void knapsackF(int size, int &maxValue, Item items[])
{
	typedef pq<BNode> NodePQ;
	NodePQ nodeQueue = NodePQ();

	BNode u(size);
	BNode v(size);

	int bestSet[globalTotalItems];
	for (int i = 0; i < globalTotalItems; i++)
	{
		bestSet[i] = 0;
	}

	// initialize root 
	v.bound = bound(v, items);
	nodeQueue.enqueue(v);

	while (!nodeQueue.empty())
	{
		v = nodeQueue.dequeue();
		// cout << "v: ";
		// v.print();

		if (v.bound > maxValue)
		{
			// filling the include array
			for (int i = 0; i < size; i++)
			{
				u.include[i] = v.include[i];
			}

			// include item scenario
			u.level = v.level + 1;
			u.weight = v.weight + items[u.level].weight;
			u.value = v.value + items[u.level].value;

			u.include[u.level] = 1;
			u.bound = bound(u, items);
			//cout << "u1: ";
			//u.print();

			// include item is promising
			if (u.bound > maxValue)
			{
			 	// cout << "u1 is promising" << endl;
				nodeQueue.enqueue(u);
			}

			if (u.weight <= globalCapacity && u.value > maxValue)
			{
				maxValue = u.value;

				for (int i = 0; i < size; i++)
				{
					bestSet[i] = u.include[i];
					// cout << bestSet[i];
				}
				// cout << endl;
			}

			// exclude item scenario
			u.level = v.level + 1;
			u.weight = v.weight;
			u.value = v.value;

			u.include[u.level] = 0;
			u.bound = bound(u, items);
			//cout << "u0: ";
			//u.print();

			// exclude item is promising
			if (u.bound > maxValue)
			{
			 	//cout << "u0 is promising" << endl;
				nodeQueue.enqueue(u);
			}
		}
	}

	// output
	int capacity = globalCapacity;
	int totalWeight = 0;
	int totalValue = 0;
	int count1 = 0;
	int count = 0;

	cout << "\n!! Output:" << endl;

	cout << "\nBestset:" << endl;
	for (int i = 0; i < globalTotalItems; i++)
	{
		cout << items[i].name << "\tBestset Value = " << bestSet[i] << endl;
		count1++;
	}

	cout << "\nItems in the Solution:" << endl;
	for (int i = 0; i < globalTotalItems; i++)
	{
		if (bestSet[i] == 1)
		{
			cout << items[i].name << "\tValue = " << items[i].value << "\tWeight = " << items[i].weight << endl;
			totalWeight += items[i].weight;
			totalValue += items[i].value;
			capacity = capacity - items[i].weight;
			count++;
		}
	}

	cout << "\nNumber of items in the solution: " << count << endl;
	cout << "Overall value of selected items: " << totalValue << endl;
	cout << "Overall weight of selected items: " << totalWeight << endl;
	cout << "Maximum weight possible: " << globalCapacity << endl;

}	// end knapsack function

// Code for node bound 
float bound(BNode n, Item items[])
{
	int j, k = 0;
	int currWeight = 0;	// curr weight in knapsack 
	float result;

	// Stops at Max Capacity 
	if (n.weight >= globalCapacity)
		return 0;
	else
	{
		j = n.level + 1;
		result = n.value;
		currWeight = n.weight;

		while (j <= globalTotalItems && globalCapacity + items[j].weight <= globalCapacity)
		{
			currWeight += items[j].weight;
			result += items[j].value;
			j++;
		}

		k = j;
		if (k <= globalTotalItems)
			result += (globalCapacity - currWeight) *((items[j].value) / items[j].weight);

		return result;
	}
}

int main()
{
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

	// To create &open file(s)
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

	Item items[totalItems];
	// bool bestset[totalItems+1];

	// fills the priority queue
	for (int x = 0; x < totalItems; x++)
	{
		inFile >> name >> value >> weight;

		Item toAdd = Item(value, weight, name);

		knapsackQueue.enqueue(toAdd);
	}

	// sorting
	for (int x = 0; x < totalItems; x++)
	{
		items[x] = knapsackQueue.dequeue();
	}

	int maxValue = 0;

	// calling knapsack function
	knapsackF(totalItems, maxValue, items);

	cout << "\n!! Max Value: " << maxValue << endl << endl;

	inFile.close();

	return 0;
}