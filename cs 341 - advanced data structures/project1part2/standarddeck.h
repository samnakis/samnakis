#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "card.h"

// !! EVERYTHING MEANT TO BE IN DECKOFCARDS.CPP IS IN THIS .H FILE !! nobody could figure out why my deckofcards.cpp wouldn't work :(

class standardDeck : public Deck {
	private:


	protected:
		// moved numCards to public

	public:
		// Class management
		standardDeck() {
			// constructor puts cardDeck on the heap with size 52
			cardDeck = new Card[52];
		}

		// runs through the suits, then runs through the faces. this will add all 52 cards to fill/make the standard deck
		void fillDeck() {
			for(int i = 1; i < 5; i++) {
				for(int k = 1; k < 14; k++) {
					Card toAdd(k,i);
					addCard(toAdd);
					// addCard(Card(k,i));
				}
			}
		}
};

#endif