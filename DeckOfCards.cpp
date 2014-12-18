#include "DeckOfCards.h"
#include "Cards.h"
#include <string>
#include <iostream>
#include <random>
#include <ctime>


using namespace std;



DeckOfCards::DeckOfCards()// constructer builds array of Type Cards to represent a deck
	: currentCard(0) // initalize to 0 to use for creating array elements
	{	
	for (int faceType = 0; faceType < 13; faceType++)
		for (int suitType = 0 ; suitType < 4; suitType++)
		{
		deck[currentCard] = Cards::Cards(faceType, suitType);
		currentCard++;
		}
	currentCard = 0; // set to 0 at end of constructor to use variable to deal	
	shuffle();
}

Cards DeckOfCards::dealCard()
{
	
	return deck[currentCard++]; // deals 0-51 and increments each time
}

Cards DeckOfCards::dealSpec(int a)
{

	return deck[a];
}
void DeckOfCards::shuffle()
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution< unsigned int> randomInt(0, 51);

	for (int i = 0; i < 51; i++)
	{
		int rndCard = randomInt(engine); // create random number int

		Cards cardSwap = deck[i]; // create duplicate of deck
		deck[i] = deck[rndCard]; // assign a random element to deck 
		deck[rndCard] = cardSwap; // assigns the initial value of deck[i] to random deck element, swapping values or shuffling
	}
}

bool DeckOfCards::moreCards() // returns true until currentCard data member reaches end of cards (51)
{
	if (currentCard <= 51)
		return true;
	else
		return false;
}




