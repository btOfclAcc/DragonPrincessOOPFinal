#include <string>
#pragma once
using namespace std;
class Item
{
private:
	string name;
	string effect;
	int effectValue;
	int uses;
	string description;
	string useMessage;

public:
	Item(string, string, int, int, string, string);
	~Item();

	const string GetName();
	const string GetEffect();
	const int GetEffectValue();
	const int GetUses();
	const string GetDescription();
	const string GetUseMessage();

	bool operator == (const Item&);
};