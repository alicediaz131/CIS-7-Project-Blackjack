#include <iostream>
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

Deck::Deck()
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 12; j++)
		{
			cardDeck [i][j] = new Card(i,j);
		}
	}
}


Card* Deck::drawRandomCard()
{
	bool isDrawn = false;
	Card* randomCard;
	do
	{
		srand(time(NULL));
		int suit = rand() % 4;
		int rank = rand() % 13;
		randomCard = cardDeck[suit][rank];
		isDrawn = randomCard->drawCard();
		
	}while (isDrawn == false);
	possibleCards--;
	return randomCard;
}

double Deck::nextHitTwentyOne(Player& p)
{
	if (p.handTotal() < 10)
		return 0.0;
	int twentyOneInt = 21 - p.handTotal();
	double chanceTwentyOne = (double)countCardsAtValue(twentyOneInt) / (double)possibleCards;


	if (p.handTotal() != p.lowestHandTotal() && p.lowestHandTotal() > 10)
	{
		twentyOneInt = 21 - p.lowestHandTotal();
		chanceTwentyOne += (double)countCardsAtValue(twentyOneInt) / (double)possibleCards;
	}
	return 100 * chanceTwentyOne;
}

double Deck::calculateBustChance(Player &p)
{
	int bustInt = 22 - p.lowestHandTotal();

	if (bustInt <= 10)
	{
		int higherCards = countCardsHigher(bustInt - 1, false);
		return 100.00 * ((double)higherCards / double(possibleCards));
	}
	else
	{
		return 0.0;
	}
}

double Deck::calculateBustTwoHits(Player& p)
{

	int bustInt = 22 - p.lowestHandTotal();
	double chance = 0;

	int arrayOfCardValues[11];
	// count the number of all cards at the same value or lower than the target number and put that number into the array
	for (int i = 0; i < 11; i++)
	{
		arrayOfCardValues[i] = countCardsAtValue(i + 1);

	}


	//subtract chance dealer gets between 17-21 on one hit
	int safeCards = 0;
	for (int i = 16 - p.handTotal(); i < 21 - p.handTotal(); i++)
	{
		safeCards += arrayOfCardValues[i];
	}

	chance -= 100 * (double)safeCards / (double)getAvailableCards();


	
	int highIndex = 17 - p.handTotal();
	if (highIndex < 11)
	{
		highIndex = 11;
	}
	
	for (int i = 0; i < highIndex; i++)
	{
		chance += 100 * ((combinatoric(arrayOfCardValues[i], 1) * combinatoric(countCardsHigher(bustInt - i + 1, false), 1)) / combinatoric(getAvailableCards() - 1, 2));
	}
	

	

	return chance;
}



int Deck::countCardsHigher(int num, bool includeAces)
{
	int higherCardCount = 0;
	int rankIndex = num - 1;
	int jHigh = 12;
	if (includeAces == false)
	{
		jHigh = 11;
	}

	
	for (int i = 0; i <= 3; i++)
	{
		for (int j = jHigh; j >= rankIndex; j--)
		{
			if (cardDeck[i][j]->getDrawnStatus() == false)
			{
				higherCardCount++;
			}
			else
			{
				if (cardDeck[i][j]->getConcealment() == true)
				{
					higherCardCount++;
				}
			}
			
		}
	}
	return higherCardCount;
}



int Deck::countCardsAtValue(int num)
{
	int cardCount = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (num == 10)
		{
			for (int j = 11; j >= 8; j--)
			{
				if (cardDeck[i][j]->getDrawnStatus() == false)
				{
					cardCount++;
				}
				else
				{
					if (cardDeck[i][j]->getConcealment() == true)
					{
						cardCount++;
					}
				}

			}
		}
		else if (num == 11 || num == 1)
		{
			if (cardDeck[i][12]->getDrawnStatus() == false)
			{
				cardCount++;
			}
			else
			{
				if (cardDeck[i][12]->getConcealment() == true)
				{
					cardCount++;
				}
			}
		}
		else
		{
			int rankIndex = findRankIndex(num);
			if (cardDeck[i][rankIndex]->getDrawnStatus() == false)
			{
				cardCount++;
			}
			else
			{
				if (cardDeck[i][rankIndex]->getConcealment() == true)
				{
					cardCount++;
				}
			}
		}

	}
	return cardCount;
}



// based on the dealer recieving two cards, one is revealing their face down card, the second would be their first hit.
double Deck::dealerHitTwentyOne(Player& d)
{
	int arrayOfCardValues[11];
	double chance = 0;
	int twentyOneInt = 21 - d.handTotal();
	// count the number of all cards at the same value or lower than the target number and put that number into the array
	for (int i = 0; i < 11; i++)
	{
		arrayOfCardValues[i] = countCardsAtValue(i + 1);
	}

	/*
	
	A single two and a single ace = 2 draws
	C(4,1)*C(4,1)/C(52,2) = 16/1326 = 1.206% chance.
	C(number of cards for low value, 1) * C(number of cards for high value, 1)/C(number of remaining possible cards - 1, 2)
	*/
	int highIndex = twentyOneInt;
	int lowIndex = 0;
	if (twentyOneInt > 11)
	{
		highIndex = 11;
		lowIndex = twentyOneInt - 12;
	}

	for (int i = lowIndex; i < twentyOneInt / 2; i++)
	{
		chance += 100 * ((combinatoric(arrayOfCardValues[i], 1) * combinatoric(arrayOfCardValues[twentyOneInt - i - 2], 1)) / combinatoric(getAvailableCards() - 1, 2));
	}
	chance += nextHitTwentyOne(d);
	return  chance;
}


int Deck::findRankIndex(int num)
{
	int rankIndex = 0;
	if (num < 10)
	{
		rankIndex = num - 2;
	}
	else if (num == 10)
	{
		rankIndex = 8;
	}
	return rankIndex;
}

void Deck::incrementPossibleCard(int num)
{
	possibleCards += num;
}


double Deck::combinatoric(int n, int r)
{
	if (n == 0)
		return 0;
	return (double)(tgamma(n + 1) / (double)(tgamma(n - r + 1) * tgamma(r+1)));
}



int Deck::getAvailableCards()
{
	return possibleCards;
}