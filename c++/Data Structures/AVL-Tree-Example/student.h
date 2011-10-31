//////////////////////////////////////////
//				student.h				//
//////////////////////////////////////////

#include <string>
#include <iostream>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	Student(int i, string l, string f, string y);
	Student();
	~Student();

	void PrintInfo();

	void SetID(int);
	int GetID();

	void SetLast(string);
	string GetLast();

	void SetFirst(string);
	string GetFirst();

	void SetYear(string);
	string GetYear();

private:
	string year;
	string last;
	string first;
	int id;
};

#endif