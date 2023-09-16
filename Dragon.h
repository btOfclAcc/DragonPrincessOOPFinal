#pragma once
#include <string>
#include <iostream>
using namespace std;

class Dragon
{
private:
	string dName;
	string dColorScales;
	string dColorEyes;
public:
	Dragon();
	Dragon(string name, string scales, string eyes);
	string getName();
	string getScales();
	string getEyes();
};
