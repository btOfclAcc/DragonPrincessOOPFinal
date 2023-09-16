#pragma once
#include <string>
#include <iostream>
using namespace std;

class Enemy
{
private:
	string name;
	int atk;
	int hp;
public:
	Enemy();
	Enemy(string name, int atk, int hp);

	string getName();
	int getAtk();
	int getHP();

	void setAtk(int val);
	void setHP(int val);
};
