#include "card.h"

string Card::suit[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
string Card::face[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}; 

Card::Card() {}

Card::Card(int x, int y) {
    face_val = x;
        suit_val = y;
}

string Card::getface() {
        return face[face_val];
} // returns the face of the card

string Card::getSuit() {
        return suit[suit_val];
} // returns the suit of the card

string Card::prettyCardName() {
      return face[face_val] + " of " + suit[suit_val];
} // returns the full name of the card