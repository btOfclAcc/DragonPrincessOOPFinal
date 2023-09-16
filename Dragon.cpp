#include "Dragon.h"
#include <string>
#include <iostream>
using namespace std;

Dragon::Dragon()
{
	dName = "Mimu";
	dColorScales = "White";
	dColorEyes = "Green";
}
Dragon::Dragon(string name, string scales, string eyes)
{
	dName = name;
	dColorScales = scales;
	dColorEyes = eyes;
}
string Dragon::getName()
{
	return dName;
}
string Dragon::getScales()
{
	return dColorScales;
}
string Dragon::getEyes()
{
	return dColorEyes;
}