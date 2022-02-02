#include "deckofcards.h"

#include <iostream>
#include <math.h>
using namespace std;

// start dealPlayers - deals half the deck to each player by running until the main deck is empty
void dealPlayers(Deck * cardDeck, Deck * player1Deck, Deck * player2Deck) {
    while(!cardDeck->isEmpty()) {
        cout << "deal test 1" << endl;
        player1Deck->addCard(cardDeck->dealCard());
        cout << "deal test 2" << endl;
        player2Deck->addCard(cardDeck->dealCard());
        cout << "deal test 3" << endl;
    }
}// end dealPlayers

// start facesMatch - gets
bool facesMatch(Card topCard, Card secondCard, Deck cardDeck) {
    int topCardPos = cardDeck.numCards()-1;
    int secondCardPos = topCardPos - 1;

    topCard = cardDeck.displayCard(topCardPos);
    secondCard = cardDeck.displayCard(secondCardPos);

    string topCardFace = topCard.getface();
    string secondCardFace = secondCard.getface();

    if(topCardFace == secondCardFace)
        return true;
    return false;
}

void cardPlay(Deck * cardDeck, Deck * player, bool &shouldCollect) {
    cout << "card test 1" << endl;
    bool shouldShuffle = true;
    cout << "card test 2" << endl;
    Card p1Card = cardDeck->dealCard();
    cout << "card test 3" << endl;
    if(cardDeck->isEmpty()) {
        cout << "card test 4" << endl;
        cardDeck->addCard(p1Card);
        cout << p1Card.prettyCardName() << endl;
        shouldCollect = false;
    }
    else {
        cout << "card test 5" << endl;
        cout << cardDeck->numCards() << endl;
        Card p2Card = cardDeck->displayCard(cardDeck->numCards()+1);
        cout << p2Card.prettyCardName() << endl;

        if(facesMatch(p1Card, p2Card, *cardDeck)) {
            player->mergeDecks(*cardDeck, true);
            shouldCollect = true;
            cardPlay(player,cardDeck,shouldCollect);
        }
        else {
            cardDeck->addCard(p1Card);
            shouldCollect = false;
        }
    }
}

void warTime(Deck * cardDeck, Deck * player1Deck, Deck * player2Deck, bool shouldCollect, int &player1Wins, int &player2Wins, int &player1Points, int &player2Points, int &winnerPoints) {
    cout << "war test 1" << endl;
    cardPlay(cardDeck, player1Deck, shouldCollect);
    cout << "war test 2" << endl;
    while((!player1Deck->isEmpty()) || (!player2Deck->isEmpty())) {
        cout << "war test 3" << endl;
        cardPlay(cardDeck, player1Deck, shouldCollect);
        cardPlay(cardDeck, player2Deck, shouldCollect);
        cout << "war test 4" << endl;
    }

    if(player1Deck->isEmpty()) {
        cout << "war test 5" << endl;
        player2Wins++;
        player2Points += player2Deck->numCards();
        winnerPoints += player2Deck->numCards();
        cout << "war test 6" << endl;
    }

    else if(player2Deck->isEmpty()) {
        cout << "war test 7" << endl;
        player1Wins++;
        player1Points += player1Deck->numCards();
        winnerPoints += player1Deck->numCards();
        cout << "war test 8" << endl;
    }
}

int main() {
    srand(time(0));

    // creates the empty decks
    Deck * cardDeck = new Deck();
    Deck * player1Deck = new Deck();
    Deck * player2Deck = new Deck();
    // Deck * battleground = new Deck();

    // status and stats variables
    int player1Wins = 0;
    int player2Wins = 0;

    int player1Points = 0;
    int player2Points = 0;
    int winnerPoints = 0;

    bool shouldCollect;

    double player1Average = 0.0;
    double player2Average = 0.0;
    double cardsLeft = 0.0;
    double totalCardsLeft = 0.0;

    Card player1Card, player2Card;

    // makes the game play 100 times
    for(int i=0; i<=100; i++) {
        cout << "test 1" << endl;
        cardDeck->fillDeck();
        cout << cardDeck->numCards() << endl;
        cardDeck->printDeck();

        cout << "test 2" << endl;
        cardDeck->shuffle();
        cout << "test 3" << endl;

        dealPlayers(cardDeck, player1Deck, player2Deck);

        cout << "test 4" << endl;

        warTime(cardDeck, player1Deck, player2Deck, shouldCollect, player1Wins, player2Wins, player1Points, player2Points, winnerPoints);

        cout << "test 5" << endl;

        if(player1Deck->isEmpty() || player2Deck->isEmpty()) {
            cardsLeft += cardDeck->numCards();
        }
        cout << "test 6" << endl;
    }

    totalCardsLeft = cardsLeft/100.0;
    player1Average = player1Points/100.0;
    player2Average = player2Points/100.0;

    // which player won more
    if(player1Wins>player2Wins) {
        cout << "player 1 won more!" << endl;
    }
    else if(player2Wins>player1Wins) { 
        cout << "player 2 won more!" << endl; 
    }
    else { cout << "both players won an equal amount!" << endl; }

    // average score of player 1
    cout << "player 1 scored an average of " << player1Average << " points per game!" << endl;

    // average score of player 2
    cout << "player 1 scored an average of " << player2Average << " points per game!" << endl;

    // average score of winning player
    cout << "the average score of the winning player each round is " << winnerPoints/100 << " points!" << endl;

    // average number of cards left in battlefield post-game
    cout << "the average number of cards left in the battlefield per game is " << totalCardsLeft << "!" << endl;

    return 0;
}