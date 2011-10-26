// main.cpp

#include <iostream>
#include <string>
#include "hashTable.h"
#include "hashTable.cpp"
#include "entry.h"
#include "entry.cpp"
#include "miscFunctions.h"
#include "time.h"
using namespace std;

int main()
{

	//generateList();
	HashTable<string> table(199);

	time_t now, after;

	time (&now);
	cout << "Start time: " << ctime(&now) << endl;

	table.processList("f500_exam.txt");

	time (&after);
	cout << "End time: " << ctime(&after) << endl;

	double dif;
	dif = difftime(after, now);
	printf("Total process time is: %.10f seconds\n", dif);

	table.printTable();

	int finish;
	cin >> finish;
	return 0;
}