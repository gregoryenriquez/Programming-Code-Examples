//////////////////////////////////////////
//				readfile.cpp			//
//////////////////////////////////////////

#include <string>
#include <fstream>
#include "roster.h"
#include "student.h"
#include "readfile.h"
#include <iostream>
using namespace std;

void readFile(Roster& R, string file)
{
	fstream data;
	data.open(file, fstream::in | fstream::out);

	string current_line;
	while (getline(data, current_line) )
	{
		int read_id;
		string read_first, read_last, read_year;
		string temp;
		char* c_str;

		size_t left = 0, right = 0;

		right = current_line.find_first_of(",");
		temp = current_line.substr(left, right-left);
		c_str = new char[temp.size()+1];
		strcpy(c_str, temp.c_str());

		read_id = atoi(c_str);

		left = right+2;
		right = current_line.find_first_of(",", left);
		read_last = current_line.substr(left, right-left);

		left = right+2;
		right = current_line.find_first_of(",", left);
		read_first = current_line.substr(left, right-left);

		left = right+2;
		right = current_line.find_first_of("\n", left);
		read_year = current_line.substr(left, right-left);

		Student* temp_student = new Student(read_id, read_last, read_first, read_year);
		R.Add(temp_student, R.root);



	}
	data.close();
}
