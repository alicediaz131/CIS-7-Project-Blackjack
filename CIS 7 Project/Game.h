#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include "User.h"

#include "Card.h"

#include <string>

using namespace std;

class Game {
private:
	
	Deck gameDeck;
	Player dealer;
	User *user;
	bool gameOver = false;
public:
	Game(User &p);
	void gameLoop();
	void tie();
	void blackJack();
	void userWin();
	void userBust();
	void dealerWin();
	void dealerBust();
	void forfeit();
	
};

#endif