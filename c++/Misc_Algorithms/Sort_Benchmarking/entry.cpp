/////////////
// entry.cpp
/////////////

#include "entry.h"
#include <string>
#include <iostream>
using namespace std;


Entry::Entry(string sym, string n)
{
	comparable = sym;
	symbol = sym;
	name = n;
}

Entry::Entry()
{
	symbol = "";
	name = "";
	comparable = "";
}

void Entry::setSymbol(string s)
{
	symbol = s;
}

string Entry::getSymbol()
{
	return symbol;
}

void Entry::setName(string s)
{
	name = s;
}

string Entry::getName()
{
	return name;
}

