#include "Item.h"

Item::Item(string t_name, string t_effect, int t_effectValue, int t_uses, string t_description, string t_useMessage)
{
	name = t_name;
	effect = t_effect;
	effectValue = t_effectValue;
	uses = t_uses;
	description = t_description;
	useMessage = t_useMessage;
}

Item::~Item()
{
}

const string Item::GetName()
{
	return name;
}

const string Item::GetEffect()
{
	return effect;
}

const int Item::GetEffectValue()
{
	return effectValue;
}

const int Item::GetUses()
{
	return uses;
}

const string Item::GetDescription()
{
	return description;
}

const string Item::GetUseMessage()
{
	return useMessage;
}

bool Item::operator==(const Item& t_item)
{
	if (name == t_item.name)
		return true;
	return false;
}