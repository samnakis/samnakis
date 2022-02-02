// CS 351: Project 4
// node.h

// Created by Sam Nakis and Maya Sanchez on 12/15/2021
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct BNode
{
	int level;
	int value;
	int weight;
	float bound;
	int include[99999];
	int size;

	BNode(int s = 0);
	BNode(int level, int value, int weight, float bound, int size);

	// operator overloading for the pq
	bool operator < (const BNode &right) const
	{
		if (bound < right.bound)
			return true;
		return false;
	}

	void print() const;
	double ratio() const;
};

// Default Constructor
BNode::BNode(int s)
{
	level = -1;
	value = 0;
	weight = 0;
	bound = 0;
	size = s;

	for (int i = 0; i < size; i++)
	{
		include[i] = 0;
	}
}

// Constructor
BNode::BNode(int v, int w, int l, float b, int s): weight(w), value(v), level(l), bound(b), size(s) {}

// Defined function for print
void BNode::print() const
{
	for (int x = 0; x < size; x++)
		cout << include[x];

	cout << " level: " << level << " value: " << value << " weight: " << weight << " bound: " << bound << endl;
}

// function to get ratio
double BNode::ratio() const
{
	return value / weight;
}