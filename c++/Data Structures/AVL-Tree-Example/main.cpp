//////////////////////////////////////////
//				main.cpp				//
//////////////////////////////////////////

#include <iostream>
#include "student.h"
#include "roster.h"
#include <string>
using namespace std;

void readFile(Roster& R, string file);
void writeFile(Roster& R);

int main()
{
	Roster R;
	string filename;
	cout << "Enter filename to read from (\"lab3.txt\" for example): ";
	cin >> filename;
	readFile(R, filename);
	cout << "Infix Traversing... " << endl;
	R.InfixTraverse(R.root);
	writeFile(R);
	
	cout << "Adding myself... " << endl;
	Student* myself = new Student(9, "Enriquez", "Gregory", "Senior");
	R.Add(myself, R.root);

	cout << "Lazy deleting Frank Lin, #3" << endl;
	R.Drop(R.root, 3);

	cout << "Infix Traversing..." << endl;
	R.InfixTraverse(R.root);

	int finish;
	cin >> finish;
	return 0;
}