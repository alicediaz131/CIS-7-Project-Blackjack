
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
	name = "Player";
}

string Player::getName()
{
	return name;
}

void Player::setName(string n)
{
	name = n;
}

void Player::givePlayerCard(Card* card)
{
	playerHand.push_back(card);
}


void Player::displayHand()
{
	cout << "\n___________________\n";
	cout << name << "'s hand. ";
	cout << "\n___________________\n";
	
	for (int i = 0; i < playerHand.size(); i++)
	{
		playerHand[i]->displayCard();
	}

	cout << "Value of Cards in " << name << "'s hand: " << handTotal() << "\n\n";
}

int Player::handTotal()
{
	int total = 0;
	for (int i = 0; i < playerHand.size(); i++)
	{
		if (playerHand[i]->getConcealment() == false)
		{
			total += playerHand[i]->getValue();
		}
	}
	if (total > 21)
	{
		total = 0;
		for (int i = 0; i < playerHand.size(); i++)
		{
			if (playerHand[i]->getConcealment() == false)
			{
				total += playerHand[i]->getAltValue();
			}
		}
	}
	return total;
}

int Player::lowestHandTotal()
{
	int total = 0;

	for (int i = 0; i < playerHand.size(); i++)
	{
		if (playerHand[i]->getConcealment() == false)
		{
			total += playerHand[i]->getAltValue();
		}
	}
	
	return total;
}

void Player::clearDeck()
{
	playerHand.clear();
}

