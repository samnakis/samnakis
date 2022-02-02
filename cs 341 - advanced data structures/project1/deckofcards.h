#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "card.h"

// !! EVERYTHING MEANT TO BE IN DECKOFCARDS.CPP IS IN THIS .H FILE !! nobody could figure out why my deckofcards.cpp wouldn't work :(

class Deck {
	private:
		Card * cardDeck;
		int deckSize;

	protected:
		// moved numCards to public

	public:
		// Class management
		Deck() {
			// constructor puts cardDeck on the heap with size 52
			cardDeck = new Card[52];
			deckSize = -1;
		}

		// start numCards - returns number of cards remaining in the deck
		int numCards() {
    		return deckSize+1;
		}// end numCards
		
		
		// start shuffle - sets a temporary card, makes a loop for 3n*number of cards. in loop - gets two random ints to swap card positions, then swaps them
		void shuffle() {
			Card temp;
			for(int i = 0; i < 3*deckSize; i++) {
				int randomInt1 = 1 + rand() % (deckSize-1);
				int randomInt2 = 1 + rand() % (deckSize-1);

				temp=cardDeck[randomInt1]; // put card 1 in a temporary card
				cardDeck[randomInt1]=cardDeck[randomInt2]; // put card 2 in card 1 spot
				cardDeck[randomInt2]=temp; // now put card 1 in card 2 spot]
			}
		}// end shuffle	


		// start dealCard - sets the top card equal to a temporary card which is equal to the next available array position in the deck, then decreases the deck size by 1 and removes the card
		Card dealCard() {
			if(deckSize > -1) {
				Card temp = cardDeck[deckSize];
				deckSize--;
				return temp;
			}
			return Card(0,0);
		}// end dealCard
		

		// start addCard - adds a card to the deck and increases deck size if there is space
		bool addCard(Card toAdd) {
			if(deckSize >= 52)
				return false;
			deckSize++;
			cardDeck[deckSize] = toAdd;
			return true;
		}// end addCard


		// start mergeDecks - sets a temporary card and while the deck you're moving to has room, deal the card into it and add it. shuffle the deck once new cards are added
		bool mergeDecks(Deck & deckToMove, bool shouldShuffle) {
			Card temp;
			while(!deckToMove.isEmpty()) {
				temp = deckToMove.dealCard();
				addCard(temp);
			}
			if(shouldShuffle)
				shuffle();
			return true;
		}// end mergeDecks


		// start fillDeck - runs through the suits, then runs through the faces. this will add all 52 cards to fill/make the standard deck
		void fillDeck() {
			for(int i = 1; i < 5; i++) {
				for(int k = 1; k < 14; k++) {
					Card toAdd(k,i);
					addCard(toAdd);
					// addCard(Card(k,i));
				}
			}
		}// end fillDeck

		
		// Display functions

		// start displayCard - shows the card of a certain position
		Card displayCard(int pos) {
			return cardDeck[pos];
		}// end displayCard


		// start isEmpty - returns if the deck is empty or not
		bool isEmpty() {
			if(deckSize == -1)
				return true;
			return false;
		}// end isEmpty		


		// start printDeck - prints out the deck nicely formatted with the prettyCardName
		void printDeck() {
			for(int i = 0; i <= deckSize; i++) {
				cout << cardDeck[i].prettyCardName() << endl;
			}
		}// end printDeck	
};

#endif