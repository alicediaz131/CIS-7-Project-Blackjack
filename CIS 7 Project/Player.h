#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"

using namespace std;
class Card;
class Player {
private:
	string name;
	
public:
	Player();
	string getName();
	void setName(string n);
	void givePlayerCard(Card *card);
	void displayHand();
	int handTotal();
	int lowestHandTotal();
	vector<Card*> playerHand;
	void clearDeck();

};

#endif
