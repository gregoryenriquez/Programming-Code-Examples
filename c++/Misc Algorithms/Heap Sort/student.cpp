//////////////////////////////////////////////
//			student.cpp						//
//////////////////////////////////////////////

#include "student.h"
#include <iostream>
using namespace std;

Student::Student(int p, string l, string f, string y)
{
	priority = p;
	last = l;
	first = f;
	year = y;
}

Student::Student()
{
	priority = 0;
	last = "";
	first = "";
	year = "";
}

void	Student::setP(int p)
{
	priority = p;
}

int		Student::getP()
{
	return priority;
}

void	Student::setLast(string l)
{
	last = l;
}

string	Student::getLast()
{
	return last;
}

void	Student::setFirst(string f)
{
	first = f;
}

string	Student::getFirst()
{
	return first;
}

void	Student::setYear(string y)
{
	year = y;
}

string	Student::getYear()
{
	return year;
}

void	Student::clearEntry()
{
	last = "";
	first = "";
	year = "";
	priority = 0;
}