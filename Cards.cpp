#include "cards.h"
#include <string>
#include <iostream>
#include <array>


using namespace std;

const string Cards::suitArray[suitSize] = { "Spades", "Hearts", "Diamonds", "Clubs" };
const string Cards::faceArray[faceSize] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


Cards::Cards(int cardFace, int cardSuit)
{
	face = (cardFace >= 0 && cardFace < faceSize) ? cardFace : 0;  // verifies input is valid or else sets to 0
	suit = (cardSuit >= 0 && cardSuit < suitSize) ? cardSuit : 0;
}


string Cards::toString() const // outputs card names from array
{

	return faceArray[face] + " of " + suitArray[suit];
}

int Cards::retFace() //return value of card as int
{
	return face;
}

int Cards::retSuit()
{
	return suit;
}
