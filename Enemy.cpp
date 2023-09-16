#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	name = "Enemy";
	atk = 1;
	hp = 10;
}
Enemy::Enemy(string name, int atk, int hp)
{
	this->name = name;
	this->atk = atk;
	this->hp = hp;
}

string Enemy::getName()
{
	return name;
}
int Enemy::getAtk()
{
	return atk;
}
int Enemy::getHP()
{
	return hp;
}

void Enemy::setAtk(int val)
{
	atk = val;
}
void Enemy::setHP(int val)
{
	hp = val;
}