// CS 351: Project 3
// item.h

//Created by Sam Nakis and Maya Sanchez on 11/5/2021

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item
{
	string name;
	int value;
	int weight;

	Item();
	Item(int, int, string);

	// Copy constructor
	Item(const Item &right)
	{
		// Instructions for how to copy one item to another
		value = right.value;
		weight = right.weight;
		name = right.name;
	}

	// operator overloading for the pq
	bool operator<(const Item &right) const {
		double ratio = value/weight;
		double rightRatio = right.value/right.weight;
		if(ratio < rightRatio)
			return true;
		return false;
	}

	void print() const;
};

// Default Constructor
Item::Item()
{
	name = "none";
	value = 0;
	weight = 0;
}

// Constructor
Item::Item(int v, int w, string n): weight(w), value(v), name(n) {}

// Defined function for print
void Item::print() const
{
	cout << name << " " << value << " " << weight << endl;
}


