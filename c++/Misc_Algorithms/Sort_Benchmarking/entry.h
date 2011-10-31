/////////////
// entry.h
/////////////

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iostream>
using namespace std;

class Entry
{
public:
	Entry(string sym, string n);
	Entry();


	string comparable;

	void setSymbol(string s);
	string getSymbol();

	void setName(string s);
	string getName();

private:
	string symbol;
	string name;

};

#endif