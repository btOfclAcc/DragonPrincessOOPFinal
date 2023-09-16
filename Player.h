#pragma once
#include "Item.h"
#include "Dragon.h"
#include <string>
#include <vector>
using namespace std;

//Need to implement inventory and equipment system

//Princess
class Player
{
private:
	string pName; //Player name, entered by player
	string pClass; //Selected by player: Adventurous, Warrior, and Pacifist (will affect stats)

	//Player stats, determined by class and may or may not change according to equipment
	int pHp;
	int pAtk;

public:
	//Constructors
	Player(); //Default name will be Felicia, Class is adventure maybe?
	Player(string pName, string pClass);

	//Getters
	string getName(); //Will be used for dialogue (EX: This is princess namehere)
	string getClass(); //Will be used for dialogue, or maybe variation (EX: warrior class gets different encounter/dialogue variation, etc)
	int getStat(int stat);

	//Prints
	void showProfile();

	//Setter & the like
	void setHp(int val);
	void setAtk(int val);
};
