
#include <iostream>
#include <string>
#include "Card.h"


using namespace std;

Card::Card(int s, int r)
{
	suit cardSuit = (suit)s;
	rank cardRank = (rank)r;
	
	setSuitSymbol('a');
	rankSymbol = 'b';

	
	if (cardRank <= 8)
	{
		value = (int)cardRank + 2;
		rankSymbol = to_string(value) + " ";
		if ((int)cardRank == 8)
		{
			rankSymbol = to_string(value);
		}
	}
	else if ((int)cardRank <= 11)
	{
		value = 10;
		if ((int)cardRank == 9)
		{
			rankSymbol = "J ";
		}
		else if ((int)cardRank == 10)
		{
			rankSymbol = "Q ";
		}
		else
		{
			rankSymbol = "K ";
		}
		
	}
	else
	{
		value = 11;
		altValue = 1;
		rankSymbol = "A ";
	}
	if ((int)cardSuit == 0)
	{
		suitSymbol = "D";
	}
	else if ((int)cardSuit == 1)
	{
		suitSymbol = "C";
	}
	else if ((int)cardSuit == 2)
	{
		suitSymbol = "H";
	}
	else
	{
		suitSymbol = "S";
	}
}


void Card::displayCard()
{
	
	if (isConcealed == false)
	{
		cout << "\n*************\n";
		cout << "* " << rankSymbol << "        *\n";
		cout << "* " << suitSymbol << "         *\n";
		cout << "*           *\n";
		cout << "*           *\n";
		cout << "*           *\n";
		cout << "*           *\n";
		cout << "*         " << rankSymbol << "*\n";
		cout << "*         " << suitSymbol << " *\n";
		cout << "*************\n\n";
	}
	else
	{
		cout << "\n*************\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*XXXXXXXXXXX*\n";
		cout << "*************\n\n";
	}

}






bool Card::drawCard()
{
	if (wasDrawn == false)
	{
		wasDrawn = true;
		return true;
	}
	else
	{
		return false;
	}
}

void Card::setSuitSymbol(char s)
{
	suitSymbol = s;
}

int Card::getValue()
{
	return value;
}

int Card::getAltValue()
{
	if (altValue == 0)
		return value;
	else
		return altValue;
}

void Card::setConcealment(bool con, Deck &deck)
{

	if (con == false && isConcealed == true)
		deck.incrementPossibleCard(-1);
	else if (con == true && isConcealed == false)
		deck.incrementPossibleCard(1);
	isConcealed = con;

}

bool Card::getConcealment()
{
	return isConcealed;
}

bool Card::getDrawnStatus()
{
	return wasDrawn;
}