//////////////////////////////////////////////
//			student.h						//
//////////////////////////////////////////////

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
public:
	Student(int p, string l, string f, string y);
	Student();
	
	void	setP(int p); // priority
	int		getP();

	void	setLast(string l);
	string	getLast();

	void	setFirst(string f);
	string	getFirst();

	void	setYear(string y);
	string	getYear();

	void	clearEntry();

	int priority;

private:
	string last;
	string first;
	string year;
};

#endif