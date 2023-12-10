#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(User &p)
{
	user = &p;
	cout << "Initializing new game\n";
	dealer.setName("Dealer");


	gameLoop();
}


void Game::gameLoop()
{
	bool firstRound = true;
	bool doubleDown = false;
	

	user->givePlayerCard(gameDeck.drawRandomCard());
	user->givePlayerCard(gameDeck.drawRandomCard());
	dealer.givePlayerCard(gameDeck.drawRandomCard());
	dealer.givePlayerCard(gameDeck.drawRandomCard());
	dealer.playerHand[0]->setConcealment(true, gameDeck);


	user->displayHand();
	system("pause");

	//check for a blackjack(s)
	if (user->handTotal() == 21)
	{
		dealer.displayHand();
		system("pause");
		dealer.playerHand[0]->setConcealment(false, gameDeck);
	}
	dealer.displayHand();
	system("pause");
	if (user->handTotal() == 21)
	{
		if (dealer.handTotal() == 21)
		{
			tie();
		}
		else
		{
			blackJack();
		}
	}



	char input = ' ';


		
	while (input != 'S' && input != 'F' && user->handTotal() < 21 && doubleDown == false)
	{
		cout << "\nYour chance to bust on next hit: " << gameDeck.calculateBustChance(*user) << "%\n";
		cout << "Your chance to hit 21 on next hit: " << gameDeck.nextHitTwentyOne(*user) << "%\n";
		cout << "Dealer's chance to hit 21 within their next hit: " << gameDeck.dealerHitTwentyOne(dealer) << "%\n";


		cout <<"\n" << user->getName() << ", what would you like to do?\n";
		cout << "Type H to Hit.\n";
		cout << "Type S to Stand.\n";
		cout << "Type F to Forfeit (Only lose half bet).\n";
		if (firstRound == true && user->getMoney() >= user->getBet())
			cout << "Type D to double down (Double your bet).\n";

		cin >> input;
		input = toupper(input);
		if (input == 'H')
		{
			cout << "\nYou hit!\n";
			user->givePlayerCard(gameDeck.drawRandomCard());
			user->displayHand();

			if (user->handTotal() == 21)
				system("pause");
		}
		else if (firstRound == true && input == 'D' && user->getMoney() >= user->getBet())
		{
			cout << "\nYou double downed!\n";
			user->setBet(user->getBet());
			user->givePlayerCard(gameDeck.drawRandomCard());
			user->playerHand[2]->setConcealment(true, gameDeck);
			user->displayHand();
			system("pause");
			doubleDown = true;
			input = 'S';
					
		}
		else if (input == 'F')
		{

			dealer.playerHand[0]->setConcealment(false, gameDeck);
			dealer.displayHand();

			forfeit();
		}
		else if (input == 'S')
		{
			cout << "\nYou chose to stand!\n";
		}
		firstRound = false;
	}



	while (gameOver == false)
	{
	//check for player bust;
			
		if (user->handTotal() > 21)
		{
			userBust();
		}
		
		if (gameOver == false)
		{
			if (dealer.playerHand[0]->getConcealment() == true)
			{
				dealer.displayHand();
				dealer.playerHand[0]->setConcealment(false, gameDeck);
				system("pause");
				dealer.displayHand();
				if (dealer.handTotal() < 17)
				{
					cout << "\nDealer's chance to bust on next hit: " << gameDeck.calculateBustChance(dealer) << "%\n";
					cout << "Dealer's chance to hit 21 on their next hit: " << gameDeck.nextHitTwentyOne(dealer) << "%\n";
				}
				system("pause");
			}

			if (dealer.handTotal() < 17)
			{
				dealer.givePlayerCard(gameDeck.drawRandomCard());
				dealer.displayHand();
				if (dealer.handTotal() < 17)
				{
					cout << "\nDealer's chance to bust on next hit: " << gameDeck.calculateBustChance(dealer) << "%\n";
					cout << "Dealer's chance to hit 21 on their next hit: " << gameDeck.nextHitTwentyOne(dealer) << "%\n";
				}
				system("pause");
			}

			if (dealer.handTotal() >= 17)
			{
				if (doubleDown == true)
				{
					user->displayHand();
					system("pause");
					user->playerHand[2]->setConcealment(false, gameDeck);
					user->displayHand();

					// check for double down bust
					if (user->handTotal() > 21)
					{
						userBust();
					}
				}
				
				if (gameOver == false)
				{
					// check for dealer bust
					if (dealer.handTotal() > 21)
					{
						dealerBust();
					}
					// check for tie
					else if (dealer.handTotal() == user->handTotal())
					{
						tie();
					}
					else if (dealer.handTotal() > user->handTotal())
					{
						dealerWin();
					}
					else
					{
						userWin();
					}
				}
			}
		}
		
	}
	
}



void Game::tie()
{
	gameOver = true;
	double money = user->getBet();
	cout << "You tied with the dealer. No one wins (Keep your bet).";
	user->modifyMoney(money);
}

void Game::blackJack()
{
	gameOver = true;
	double money = user->getBet() * 2.5;
	cout << "You got a blackjack! You won: $" << money-user->getBet();
	user->modifyMoney(money);
}

void Game::userWin()
{
	gameOver = true;
	double money = user->getBet() * 2;
	cout << "You got more than the dealer! You won: $" << money/2;
	user->modifyMoney(money);
}

void Game::userBust()
{
	gameOver = true;
	cout << "You have busted. Better luck next time! You lose: $" << user->getBet();
}

void Game::dealerWin()
{
	gameOver = true;
	cout << "You got less than the dealer. Better luck next time! You lose: $" << user->getBet();
}

void Game::dealerBust()
{
	gameOver = true;
	double money = user->getBet() * 2;
	cout << "The dealer busted. You won: $" << money/2;
	user->modifyMoney(money);
}

void Game::forfeit()
{
	gameOver = true;
	double money = user->getBet() / 2;
	cout << "\nYou have forfeited. You only lose: $" << money;
	user->modifyMoney(money);
}