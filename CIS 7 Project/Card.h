#ifndef CARD_H
#define CARD_H
#include <string>
#include "Deck.h"

using namespace std;
class Deck;

class Card {
private:
	int value;
	int altValue = 0;
	enum suit { DIAMONDS, CLUBS, HEARTS, SPADES };
	enum rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
	suit cardSuit;
	rank cardRank;

	bool isConcealed = false;
	bool wasDrawn = false;
public:
	Card(int s, int r);
	void displayCard();
	bool drawCard();
	string suitSymbol = "";
	string rankSymbol = "";
	void setSuitSymbol(char s);
	int getValue();
	int getAltValue();
	void setConcealment(bool con, Deck &deck);
	bool getConcealment();
	bool getDrawnStatus();
};

#endif
