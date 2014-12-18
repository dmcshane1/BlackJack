#include "Cards.h"

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H




class DeckOfCards
{
public:
	DeckOfCards();
	
	static const size_t deckSize = 52;
	int currentCard;
	Cards dealCard();
	Cards dealSpec(int);
	void shuffle();
	bool moreCards();
protected:
	int a;
	int b;
	Cards deck[deckSize];
	
};

#endif
