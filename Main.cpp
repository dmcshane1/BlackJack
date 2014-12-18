#include "Cards.h"
#include "DeckOfCards.h"
#include "Black.h"
#include <iostream>
#include <iomanip>

using namespace std;

void potAdd(int*, int);
void potSub(int*, int);

int main()
{

	char hit = 'a';
	char run;
	bool over = false;
	bool cont = true;
	bool win = false;
	int pot = 500;
	int bet = 0;


	

	while (cont == true)
	{
		Black game;

		game.dealer();
		cout << "\nHow much would you like to bet? You currently have $" << pot << " $";

		cin >> bet;

		while (bet > pot)
		{
			cout << "You cannot bet more than you have, please enter valid bet: $";
			cin >> bet;
		}

		cout << "\nYou are betting: " << bet << "\n";
		cout << "\nWould you like to hit? (Y/N) ";
		cin >> hit;

		while (hit == 'y' || hit == 'Y')
		{
			over = game.hit();
			if (over == true)
				break;
			cout << "hit again?\n";

			cin >> hit;
		}

		if (over == true) // doesn't show dealer sequence and skips to lose
		{
			win = false;
		}

		if (over == false) //player didn't go over so do dealer sequence
		{
			win = game.stand(); //member function returns bool, true if player win, false if lose.
		}

		if (win == true)
		{
			potAdd(&pot, bet);
		}

		if (win == false)
		{
			potSub(&pot, bet);
		}
		cout << "You now have a pot worth $" << pot << "\n";

		if (pot <= 0)
		{
			cout << "You are out of money\n";	
			pot = 500;
		}

		cout << "\nPlay again? (Y/N) ";

		cin >> run;
		if (run == 'Y' || run == 'y')
		{
			cont = true;
		}
		else
		{
			cont == false;
			return 0;
		}
	}


	system("PAUSE");
	

}

void potAdd(int *p, int b)
{
	if (*p > b)
	*p += b;
}

void potSub(int *p, int b)
{
	*p -= b;

}