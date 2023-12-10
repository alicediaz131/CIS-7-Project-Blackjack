#ifndef USER_H
#define USER_H
#include <string>
#include "Player.h"

using namespace std;

class User: public Player {
private:
	double money;
	double bet;
public:
	double getMoney();
	void win();
	void winBlackJack();
	void tie();
	double getBet();
	void setBet(double b);
	void resetBet();
	void modifyMoney(double m);
	User(string n);
};

#endif
