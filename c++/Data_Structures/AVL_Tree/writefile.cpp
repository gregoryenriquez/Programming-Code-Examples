//////////////////////////////////////////
//				writefile.cpp			//
//////////////////////////////////////////

#include <string>
#include <fstream>
#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

void writeFile(Roster& R)
{
	fstream data;
	data.open("outFile.txt", fstream::out);

	string whole_roster;
	R.PostFixWrite(R.root, whole_roster);

	data << whole_roster;

	data.close();
	
}