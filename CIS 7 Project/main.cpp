#include <string>
#include <iostream>
#include "Game.h"
#include "User.h"

using namespace std;

void startNewGame(User*);

int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	User player(name);

	startNewGame(&player);

	if (player.getMoney() <= 0.0)
	{
		cout << "\n\nYou've gone bankrupt!";
	}
	cout << "\n\nGoodbye . . .\n\n";
	system("pause");
}

void startNewGame(User *player)
{
	char input = ' ';
	double betAmount = 0.0;

		do {
			player->clearDeck();
			player->resetBet();
			cout << "\n\nHello " << player->getName() << ", you have $" << player->getMoney() << ". \n";
			cout << "Start new game? (Y/N)\n";
			cin >> input;
			input = toupper(input);
			if (input == 'Y')
			{

				cout << "Enter the amount you would like to bet: $";
				cin >> betAmount;
				while (betAmount < 0 || betAmount > player->getMoney())
				{
					cout << "Invalid input. Enter an amount greater than 0 and less than $" << player->getMoney() << ". \n$";
					cin >> betAmount;
				}
				player->setBet(betAmount);
				cout << "You have bet $" << player->getBet() << "\n";
				Game newGame(*player);
			}
			else if (input == 'N')
			{
				return;
			}
		} while (input != 'N' && player->getMoney() > 0.0);

	
}