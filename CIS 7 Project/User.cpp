
#include <iostream>
#include "User.h"

using namespace std;

User::User(string n)
{
	this->setName(n);
	money = 1000.00;
	bet = 0;
}

double User::getMoney()
{
	return money;
}


void User::win()
{
	money = money + (bet * 2);
}

void User::winBlackJack()
{
	money = money + (bet * 2.5);
}

void User::modifyMoney(double m)
{
	money += m;
}

void User::tie()
{
	money = money + bet;
}

double User::getBet()
{
	return bet;
}


void User::setBet(double b)
{
	bet += b;
	money -= b;
}

void User::resetBet()
{
	bet = 0;
}