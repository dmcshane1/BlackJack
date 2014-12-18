#ifndef BLACK_H
#define BLACK_H


#include "DeckOfCards.h"
#include "Cards.h"

static const size_t handSize = 6; // Assumes neither player nor dealer draws more than 6 cards

class Black : public DeckOfCards //derive class black from DeckOfCards
{
public:
	Black();
	~Black();
	void dealPlayer();
	Cards showCard(int); // this function is used to return a card object 
	void dealer();		 //so that we can use Cards function retFace to get an int value
	int evalCard(int); //changes int value of a card to scoring value
	bool hit(); //adds card to player, returns bool value to determine if player went over 21
	bool stand(); // Dealer sequence when player is done drawing
				  // returns bool value to determine w/l
protected:	
	Cards handArray[handSize]; //stores 6 CARDS objects for player
	Cards dealerHand[handSize]; //stores 6 CARDS objects for dealer
	int face[handSize]; //stores 6 INT values for player, used for scoring
	int dface[handSize]; //sotres 6 INT values for dealer, used for scoring

	int score;
	int dealCount; // tracks how many cards Player has been dealt
	int dealerCount; // initialize at 6 to avoid dealing dealer cards in player hand
	int dealerScore;
	int dhCount; // tracks how many cards Dealer has been dealt
};

#endif
