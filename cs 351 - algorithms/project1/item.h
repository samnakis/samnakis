// CS 351: Project 1
//item.h

//Created by Sam Nakis and Maya Sanchez on 10/12/2021

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

	double ratio() const;

	void print() const;

	bool operator < (const Item &a) const;

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

// Defined function for ratio
double Item::ratio() const
{
	return (value / weight);
}

// Defined function for print
void Item::print() const
{
	cout << name << " " << value << " " << weight << endl;
}

// Defined function for operator
bool Item::operator < (const Item &right) const
{
	if (ratio() < right.ratio())
		return true;

	return false;
}