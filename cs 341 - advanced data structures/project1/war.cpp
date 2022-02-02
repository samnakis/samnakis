#include "deckofcards.h"

#include <iostream>
#include <math.h>
using namespace std;

// start dealPlayers - deals half the deck to each player by running until the main deck is empty
void dealPlayers(Deck * cardDeck, Deck * player1Deck, Deck * player2Deck) {
    while(!cardDeck->isEmpty()) {
        player1Deck->addCard(cardDeck->dealCard());
        player2Deck->addCard(cardDeck->dealCard());
    }
}// end dealPlayers

// start warTime - this is what makes the actual game play out
void warTime(Deck * cardDeck, Deck * player1Deck, Deck * player2Deck, int &player1Wins, int &player2Wins, int &player1Points, int &player2Points, int &winnerPoints, int &cardsLeft) {
    // run while both players have cards
    while(!player1Deck->isEmpty() && !player2Deck->isEmpty()) {
        // player 1 adds card to middle and check to see if there is over one card in the middle to compare to, if so, see if they match and merge if necessary
        cardDeck->addCard(player1Deck->dealCard());
        if(cardDeck->numCards() > 1) {
            if(cardDeck->displayCard(cardDeck->numCards()-1).getface() == cardDeck->displayCard(cardDeck->numCards()-2).getface()) {
                player1Deck->mergeDecks(*cardDeck, true);
            }
        }

        // player 2 adds card to middle and check to see if there is over one card in the middle to compare to, if so, see if they match and merge if necessary
        cardDeck->addCard(player2Deck->dealCard());
        if(cardDeck->numCards() > 1) {
            if(cardDeck->displayCard(cardDeck->numCards()-1).getface() == cardDeck->displayCard(cardDeck->numCards()-2).getface()) {
                player2Deck->mergeDecks(*cardDeck, true);
            }
        }
    }

    // player 1 wins
    if(player2Deck->isEmpty()) {
        player1Wins++;
        player1Points += player1Deck->numCards();
        winnerPoints += player1Deck->numCards();
        cardsLeft += cardDeck->numCards();
        
    }

    // player 2 wins
    else if(player1Deck->isEmpty()) {
        player2Wins++;
        player2Points += player2Deck->numCards();
        winnerPoints += player2Deck->numCards();
        cardsLeft += cardDeck->numCards();
    }
}// end warTime

int main() {
    srand(time(0));

    // creates the empty decks
    Deck * cardDeck = new Deck();
    Deck * player1Deck = new Deck();
    Deck * player2Deck = new Deck();

    // status and stats variables
    int player1Wins = 0;
    int player2Wins = 0;

    int player1Points = 0;
    int player2Points = 0;
    int winnerPoints = 0;

    double player1Average = 0.0;
    double player2Average = 0.0;
    double winnerPointsAverage = 0.0;

    int cardsLeft = 0;
    double cardsLeftAverage = 0.0;

    Card player1Card, player2Card;

    // makes the game play 100 times
    for(int i=0; i<=100; i++) {
        cardDeck->fillDeck();

        cardDeck->shuffle();

        dealPlayers(cardDeck, player1Deck, player2Deck);

        warTime(cardDeck, player1Deck, player2Deck, player1Wins, player2Wins, player1Points, player2Points, winnerPoints, cardsLeft);
    }

    // calculating the stats
    cardsLeftAverage = cardsLeft/100.0;
    player1Average = player1Points/100.0;
    player2Average = player2Points/100.0;
    winnerPointsAverage = winnerPoints/100.0;

    cout << "!! game stats !!" << endl << endl;

    // which player won more
    if(player1Wins>player2Wins) {
        cout << "*player with most wins: player 1" << endl;
    }
    else if(player2Wins>player1Wins) { 
        cout << "*player with most wins: player 1" << endl; 
    }
    else { cout << "*player with most wins: neither! it's a tie!" << endl; }

    // average score of player 1
    cout << "*player 1's average points: " << player1Average << endl;

    // average score of player 2
    cout << "*player 2's average points: " << player2Average << endl;

    // average score of winning player
    cout << "*the average score of the winning player: " << winnerPointsAverage << endl;

    // average number of cards left in battlefield post-game
    cout << "*the average number of cards left in the battlefield per game: " << cardsLeftAverage << endl;

    cout << endl << "thank for playing!" << endl;;

    // no memory leaks :) you're welcome thomas
    delete cardDeck;
    delete player1Deck;
    delete player2Deck;

    return 0;
}