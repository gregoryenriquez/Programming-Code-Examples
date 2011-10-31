//////////////////////////////////////////
//				student.cpp				//
//////////////////////////////////////////

#include "student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int i, string l, string f, string y)
{
	id = i;
	last = l;
	first = f;
	year = y;
}

Student::Student()
{
	id = 0;
	last = "";
	first = "";
	year = "";
}

Student::~Student()
{
}

void Student::PrintInfo()
{
	//cout << "//////////////////////////////////" << endl;
	cout << id << "\t" << last << "\t" << first << "\t" << year << endl;
	//cout << "//////////////////////////////////" << endl << endl;
}

void Student::SetID(int i)
{
	id = i;
}

int Student::GetID()
{
	return id;
}

void Student::SetLast(string s)
{
	last = s;
}

string Student::GetLast()
{
	return last;
}

void Student::SetFirst(string s)
{
	first = s;
}

string Student::GetFirst()
{
	return first;
}

void Student::SetYear(string s)
{
	year = s;
}

string Student::GetYear()
{
	return year;
}
