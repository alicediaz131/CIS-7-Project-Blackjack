#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "Player.h"

#include <string>

using namespace std;

class Player;
class Card;

class Deck {
private:
	Card* cardDeck[4][13];
	int possibleCards = 52;

public:
	Deck();

	Card *drawRandomCard();
	double calculateBustChance(Player & p);
	double calculateBustTwoHits(Player& p);
	double nextHitTwentyOne(Player& p);
	double dealerHitTwentyOne(Player& p);
	int countCardsAtValue(int num);
	int countCardsHigher(int num, bool includeAces);
	int findRankIndex(int num);
	void incrementPossibleCard(int num);
	int getAvailableCards();

	double combinatoric(int n, int r);

	int combinationsToValue(int num);
	double chanceToGetValue(int value, int cards, int drawnCards);
};

#endif