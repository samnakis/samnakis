#include "deckofcards.h"

#include <iostream>
#include <math.h>
using namespace std;

/*
steps
1. split deck in half
2. assign each player a half of the deck
3. p1 places a card on the battleground
4. then p2, and on and on
5. if player places a card that matches the face of the one under it, they take the cards
6. player who got the cards starts the new pile
7. go until only one player has cards left, they win the round
8. they get points = to the number of cards they have left
9. game played 100 times
10. report stats
*/

int main() {
    srand(time(0));

    // creates the empty decks
    Deck * cardDeck = new Deck();
    Deck * player1Deck = new Deck();
    Deck * player2Deck = new Deck();
    Deck * battleground = new Deck();

    // runs through the suits, then runs through the faces. this will add all 52 cards to fill/make the standard deck
    for(int i = 1; i < 5; i++) {
        for(int k = 1; k < 14; k++) {
            cardDeck->addCard(Card(k,i));
        }
    }

    cardDeck->shuffle();

    // deal half of the deck to each player
    while(!cardDeck->isEmpty()) {
        player1Deck->addCard(cardDeck->dealCard());
        player2Deck->addCard(cardDeck->dealCard());
    }

    // making the game play
    // status and stats variables
    int active = 1;
    int currentPlayer = 1;

    int player1Wins = 0;
    int player2Wins = 0;

    int player1Points = 0;
    int player2Points = 0;
    int winnerPoints = 0;

    int cardsLeft = 0;
    int gamesPlayed = 0;

    // makes the game play 100 times
    for(int i=0; i<=100; i++) {
        cout << "test 1" << endl;
        while(active == 1) {
            cout << "test 2" << endl;
            // player 1 turn
            if(currentPlayer = 1 && !player1Deck->isEmpty() && !player2Deck->isEmpty()) {
                cout << "test 3" << endl;
                // p1 adds card to middle
                battleground->addCard(player1Deck->dealCard());
                cout << "test 4" << endl;

                // if the number of cards in the middle is higher than 1 (so it has something to compare to), check if the faces match
                if(battleground->numCards()>1) {
                    cout << "test 5" << endl;
                    int topCardPos = battleground->numCards()-1;
                    int secondCardPos = topCardPos - 1;

                    cout << "test 5.5" << endl;
                    Card topCard = battleground->displayCard(topCardPos);
                    Card secondCard = battleground->displayCard(secondCardPos);

                    cout << "test 5.75" << endl;
                    cout << battleground->numCards() << endl;
                    cout << topCard.prettyCardName() << endl;
                    cout << secondCard.prettyCardName() << endl;
                    cout << "test 6" << endl;

                    // if faces match, merge middle deck with p1's
                    if(topCard.getface() == secondCard.getface()) {
                        player1Deck->mergeDecks(* battleground, true);
                        currentPlayer = 1;
                        active = 0;
                        cout << "test 7" << endl;
                    }
                    else { 
                        currentPlayer = 2;
                        active = 0;
                        cout << "test 8" << endl;
                    }
                }
                else { currentPlayer = 2; }
                cout << "test 9" << endl;
            }

            // if p2 runs out of cards, p1 wins and round is over. collect stats info
            else if(player2Deck->isEmpty()) {
                cout << "test 10" << endl;
                player1Wins++;
                gamesPlayed++;
                player1Points += player1Deck->numCards();
                winnerPoints += player1Deck->numCards();
                cardsLeft += battleground->numCards();
                currentPlayer = 1;
                active = 0;
            }


            // player 2 turn
            if(currentPlayer = 2 && !player1Deck->isEmpty() && !player2Deck->isEmpty()) {
                cout << "test 11" << endl;
                // p2 adds card to middle
                battleground->addCard(player2Deck->dealCard());
                cout << "test 12" << endl;

                // if the number of cards in the middle is higher than 1 (so it has something to compare to), check if the faces match
                if(battleground->numCards()>1) {
                    cout << "test 13" << endl;
                    int topCardPos = battleground->numCards()-1;
                    int secondCardPos = topCardPos - 1;

                    cout << "test 13.5" << endl;
                    Card topCard = battleground->displayCard(topCardPos);
                    Card secondCard = battleground->displayCard(secondCardPos);

                    cout << "test 13.75" << endl;
                    cout << battleground->numCards() << endl;
                    cout << topCard.prettyCardName() << endl;
                    cout << secondCard.prettyCardName() << endl;
                    cout << "test 14" << endl;

                    // if faces match, merge middle deck with p2's
                    if(topCard.getface() == secondCard.getface()) {
                        player2Deck->mergeDecks(* battleground, true);
                        currentPlayer = 2;
                        active = 0;
                        cout << "test 15" << endl;
                    }
                    else { 
                        currentPlayer = 1;
                        active = 0;
                        cout << "test 16" << endl;
                    }
                }
                else { currentPlayer = 1; }
                cout << "test 17" << endl;
            }

            // if p1 runs out of cards, p1 wins and round is over. collect stats info
            else if(player1Deck->isEmpty()) {
                cout << "test 18" << endl;
                player2Wins++;
                gamesPlayed++;
                player2Points += player2Deck->numCards();
                winnerPoints += player2Deck->numCards();
                cardsLeft += battleground->numCards();
                currentPlayer = 1;
                active = 0;
            }
        }

        if(active == 0) {
            cout << "test 19" << endl;
            cout << "games played: " << gamesPlayed << endl;
            cout << "player 1 wins: " << player1Wins <<endl;
            cout << "player 2 wins: " << player2Wins <<endl;
            // if the game has been played 100 times, print stats
            if(gamesPlayed==100) {
                cout << "test 20" << endl;
                // which player won more
                if(player1Wins>player2Wins) {
                    cout << "player 1 won more!" << endl;
                }
                else if(player2Wins>player1Wins) { 
                    cout << "player 2 won more!" << endl; 
                }
                else { cout << "both players won an equal amount!" << endl; }

                // average score of player 1
                cout << "player 1 scored an average of " << player1Points/100 << " points per game!" << endl;

                // average score of player 2
                cout << "player 1 scored an average of " << player2Points/100 << " points per game!" << endl;

                // average score of winning player
                cout << "the average score of the winning player each round is " << winnerPoints/100 << " points!" << endl;

                // average number of cards left in battlefield post-game
                cout << "the average number of cards left in the battlefield per game is " << cardsLeft/100 << "!" << endl;
            }

            // resets game if under 100 games have been played
            else {
                for(int i = 1; i < 5; i++) {
                    for(int k = 1; k < 14; k++) {
                        cardDeck->addCard(Card(k,i));
                    }
                }

                cardDeck->shuffle();

                while(!cardDeck->isEmpty()) {
                    player1Deck->addCard(cardDeck->dealCard());
                    player2Deck->addCard(cardDeck->dealCard());
                }
                active = 1;
                cout << "test 21" << endl;
            }
        }
    }

  
    

    // playing the game
    // player one
    



    // testing!
    // cout << "p1 deck" << endl;
    // player1Deck->printDeck();
    // cout << endl << "p2 deck" << endl;
    // player2Deck->printDeck();

    




    // TESTING !!!!!!
    // // tests printDeck
    // cardDeck->printDeck();

    // // tests mergeDeck
    // int index=0;

    // while(index<12) {
	// 	newDeck->addCard(cardDeck->dealCard());
    //     index++;
	// }

    // cardDeck->mergeDecks(* newDeck, true);


    // checking if the deck shuffles
    // cardDeck->shuffle();

    // while(!cardDeck->isEmpty()) {
    //     cardDeck->printDeck();
    // }


    // // checking if all of the cards are being entered into deck
    // while(!cardDeck->isEmpty()) {
    //     cout << cardDeck->dealCard().prettyCardName() << endl;
    // }

    return 0;
}