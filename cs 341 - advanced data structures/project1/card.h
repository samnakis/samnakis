#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card {
	private: 
		int face_val;
		int suit_val;

	public:
		// Class management
        Card();
		Card(int, int);
		static string face[14];
		static string suit[5];
		
		// Display functions
		string getface();           // returns the face of the card
		string getSuit();           // returns the suit of the card
		string prettyCardName();    // returns a string with the full name of the card, e.g. "Ace of Spades"
};

#endif