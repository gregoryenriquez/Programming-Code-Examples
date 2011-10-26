//////////////////////////////////////////////
//			main.cpp						//
//////////////////////////////////////////////

#include <iostream>
#include "heap.h"
#include "student.h"
using namespace std;

int main()
{
	Heap roster(14);
	roster.readFile("lab3.txt");
	cout << endl << "Print Heap (Before sort): " << endl;
	roster.printHeap();
	cout << endl << "Sorted Heap" << endl;
	roster.clearAndPrintSortedHeap();
	int finish;
	cin >> finish;
}