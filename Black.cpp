#include "Black.h"
#include "Cards.h"
#include <iostream>

using namespace std;



Black::Black ()
{
	dealCount = 0;
	score = 0;
	dealerCount = 6; 
	dealerScore = 0;  
	dhCount = 0;  //using for dealerHand array



	shuffle();
	dealPlayer();
	
}

Black::~Black()
{
	cout << "\nShuffling Cards!\n\n"; // Verifies that cards are reshuffled when object
}								      // is reinitialized
void Black::dealPlayer()
{
	cout << "Your cards are: \n\n";

	for (int i = 0; i < 2; i++) // deal a player 2 cards in an array of Cards objects.
	{	
		handArray[i] = deck[i]; // copies CARDS objects from deck into player array
		cout << "Card " << i << ": ";
		cout << showCard(i).toString(); // Outputs string of CARDS object.
		cout << "\n";

		handArray[i] = deck[i]; //copies to user hand
		face[i] = showCard(i).retFace(); //copies card value to int
		face[i] = evalCard(face[i]);

		dealCount++; //counter to keep track of cards;
	}
	score = face[0] + face[1];
}


Cards Black::showCard(int a) // allows an int to be returned as a CARDS object, so we can use CARDS member functions
{
	return deck[a]; 
}


int Black::evalCard(int b)
{
	switch (b) // assigns scoring value to cards
	{
	case 0:
		b = 11; //automatically assigns ace value of 11
		break;
	case 1:
		b = 2;
		break;
	case 2:
		b = 3;
		break;
	case 3:
		b = 4;
		break;
	case 4:
		b = 5;
		break;
	case 5:
		b = 6;
		break;
	case 6:
		b = 7;
		break;
	case 7:
		b = 8;
		break;
	case 8:
		b = 9;
		break;
	case 9:
		b = 10;
		break;
	case 10:
		b = 10;
		break;
	case 11:
		b = 10;
		break;
	case 12:
		b = 10;
		break;
		
	}

		return b;
}


bool Black::hit() 
{

	handArray[dealCount] = deck[dealCount]; //copies to user hand
	face[dealCount] = showCard(dealCount).retFace(); //copies card value to int
	face[dealCount] = evalCard(face[dealCount]); // evaluates card's score

	cout << "\nCard " << dealCount << ": ";
	cout << showCard(dealCount).toString();
	cout << "\n";

	 score = score +  face[dealCount];
	 dealCount++; 

	if (score > 21) // checks for ace if score is over 21
	{
		for (int i = 0; i <= dealCount; i++)
		{
			if (face[i] == 11) // if there is an ace,
			{
				score = score - face[i]; // subtracts the 11 ace value from score
				face[i] = 1; // sets that value to 1
				score = score + face[i]; //re adds to score as a 1 ace value
				break; // breaks loop in case there is multiple aces.
				
			}
		}
	}

	if (score > 21)
	{
		cout << "\nYou went over, you lose\n";
		return true;

	}
	return false;
}

void Black::dealer()
{


	for (int i = 0; i < 2; i++)
	{
		dealerHand[i] = deck[dealerCount]; // copies CARDS objects from deck into dealer array
		dface[i] = showCard(dealerCount).retFace(); // copies value of dealers card into int
		dface[i] = evalCard(dface[i]); // stores card score value
		dealerCount++;
		dhCount++;

	}

	dealerScore = dface[0] + dface[1];
	cout << "\nDealer's face up card is " << showCard(6).toString() << "\n"; // Reveals dealers face up card


}

bool Black::stand()
{
	cout << "The value of your cards is " << score << "\n";
	cout << "\nThe dealers hole card is " << showCard(7).toString() << "\n";

	while (dealerScore < score)
	{
		cout << "Dealer is going to draw another card\n";

		dealerHand[dhCount] = deck[dealerCount]; // copies card to dealer hand
		dface[dhCount] = showCard(dealerCount).retFace(); // Changes card to int
		dface[dhCount] = evalCard(dface[dhCount]); // Changes int to card score

		
		dealerScore = dealerScore + dface[dhCount];

		cout << "Dealer drew a " << showCard(dealerCount).toString()  << "\n";
		cout << "Dealer's score is now " << dealerScore << "\n";

		if (dealerScore > 21) // checks for ace if score is over 21
		{
			for (int i = 0; i <= dhCount; i++)
			{
				if (dface[i] == 11) // if there is an ace,
				{
					dealerScore = dealerScore - face[i]; // subtracts the 11 ace value from score
					dface[i] = 1; // sets that value to 1
					dealerScore = dealerScore + face[i]; //re adds to score as a 1 ace value
					break; // breaks loop in case there is multiple aces.

				}
			}
		}

		dhCount++;
		dealerCount++;
	}

	if (dealerScore == score)
	{
		cout << "Dealer has matched your score, you lose!\n";
		return false;
	}

	if (dealerScore > score && dealerScore <= 21)
	{
		cout << "\nDealer's cards have a higher value, You Lose!\n";
		return false;
	}


	if (dealerScore > 21)
	{
		cout << "\nThe Dealer went over, You Win!\n";
		return true;
	}

}