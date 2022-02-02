// CS 351: Project 1
//randoNum.h

//Created by Sam Nakis and Maya Sanchez on 10/12/2021

// This file is creating a random file generator to use once the user inputs..
// their desired items and capacity.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h>

void makeTextFile(int inputNOI, int knapsackCapacity)
{
	srand(time(0));

	string outName;
	int outNameNum;
	int pesos;
	int pounds;

	// Creates the alphabet used to name items. 
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int numberName = 1;

	// To create and open file
	ofstream outFile;
	outFile.open("niceFile.txt");

	outFile << inputNOI << " " << knapsackCapacity << endl;

	// This if causes the item name to change from alphabet to numbers..
	// depending if the input (total items) is greater than 26. 
	if (inputNOI <= 26)
	{
		for (int x = 0; x < inputNOI; x++)
		{
			outName = alphabet[x];

			int randomPesos = 1 + rand() % (3 *inputNOI);
			pesos = randomPesos;

			int randomPounds = 1 + rand() % (3 *inputNOI);
			pounds = randomPounds;

			outFile << outName << " " << pesos << " " << pounds << endl;
		}
	}
	else if (inputNOI > 26)
	{
		for (int x = 0; x < inputNOI; x++)
		{
			outNameNum = numberName++;

			int randomPesos = 1 + rand() % (3 *inputNOI);
			pesos = randomPesos;

			int randomPounds = 1 + rand() % (3 *inputNOI);
			pounds = randomPounds;

			outFile << "item" << outNameNum << " " << pesos << " " << pounds << endl;
		}
	}
	else
	{
		cout << "something went wrong!" << endl;
	}
	outFile.close();
}