#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"
#pragma once
using namespace std;
class Inventory
{
private:
	struct invenItem {
		Item item;
		int uses;
		int count;
	};

	vector<invenItem> inventory;

public:
	Inventory();
	~Inventory();

	const vector<invenItem> GetInventory();
	void SetInventory(vector<invenItem>);

	void PrintInventory();
	void AddItem(Item);
	void UseItem(Item);
};
