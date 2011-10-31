/////////////
// miscFunctions.cpp
/////////////
#include "miscFunctions.h"
#include "allsort.h"
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

double quicksort(string file_name, int s_in, int s_by);
double mergesort(string file_name, int s_in, int s_by);
double heapsort(string file_name, int s_in, int s_by);
double bubblesort(string file_name, int s_in, int s_by);
void stlsort(string file_name, int s_in, int s_by);

void runUI(string s)
{
	string file_to_read = s;
	int select = 0;
	int sort_by = 2;
	int sort_in = 2;
	time_t now, after;
	double allComp = 0;
	double dif;
	double temp;
	int runs = 100;

	
	while (1) 
	{
		switch(select)
		{
		default: // menu
			system("cls");
			
			cout << "Sort in: " << endl <<
				"1. Ascending" << endl <<
				"2. Descending" << endl <<
				"Selection: ";
			cin >> sort_in;
			while ( sort_in < 0 || sort_in > 2)
			{
				cout << endl << "Invalid, re-enter: ";
				cin >> sort_in;
			}
			system("cls");
			
			// symbol, name
			cout << "Sort by: " << endl <<
				"1. Symbol" << endl <<
				"2. Name " << endl <<
				"Selection: ";
			cin >> sort_by;
			while ( sort_by > 2 || sort_by < 0)
			{
				cout << endl << "Invalid, re-enter: ";
				cin >> sort_by;
			}
			system("cls");
			
			cout << "___Sort method:___ " << endl <<
				"1. Quicksort" << endl <<
				"2. Mergesort" << endl <<
				"3. Heapsort" << endl <<
				"4. Bubblesort" << endl <<
				"5. STL sort" << endl <<
				"6. Exit" << endl <<
				"7. Run all" << endl;
				"Selection: ";
			cin >> select;
			while ((select > 7) || (select < 0))
			{
				cout << endl << "Invalid, re-enter:";
				cin >> select;
			}
			break;
		case 1: // quicksort
			cout << "Running Quick Sort " << runs << " times...";
			time(&now);
			temp;
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = quicksort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Quick Sort Analysis___" << endl 
				<< "Start time: " << now << endl
				<< "End time: " << after << endl
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif / runs << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;
			select = 6;
			break;
		case 2: // mergesort
			cout << "Running Merge Sort " << runs << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = mergesort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Mergesort Analysis___" << endl 
				<< "Start time: " << now << endl
				<< "Average run time: " << (dif / runs) << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;
			select = 6;
			break;
		case 3: // heapsort
			cout << "Running Heap Sort " << runs << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = heapsort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Heap Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << (dif / runs) << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;
			select = 6;
			break;
		case 4: // bubblesort
			cout << "Running Bubble sort " << 5 << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < 5; i++)
			{
				temp = bubblesort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << "___Bubble Sort Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif / 5 << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/5 << endl;
			select = 6;
			break;
		case 5: // stl sort
			
			cout << "Running STL sort " << runs << " times..." << endl;
			time(&now);
			for (int i = 0; i < runs; i++)
				stlsort(file_to_read, sort_in, sort_by);
			time(&after);
			dif = difftime(after, now);
			cout << endl << "___STL Sort Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif / runs << " sec" << endl;
			select = 6;
			break;
		case 6:
			return;
			break;
		case 7:
			cout << "_______________________________________" << endl;
			cout << "Running Quick Sort " << runs << " times...";
			time(&now);
			temp = 0;
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = quicksort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Quick Sort Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif /runs << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;

			cout << "_______________________________________" << endl;
						cout << "Running Merge Sort " << runs << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = mergesort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Mergesort Analysis___" << endl 
				<< "Start time: " << now << endl
				<< "Average run time: " << (dif / runs) << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;

			cout << "_______________________________________" << endl;
			cout << "Running Heap Sort " << runs << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < runs; i++)
			{
				temp = heapsort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << endl << "___Heap Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << (dif / runs) << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/runs << endl;

			cout << "_______________________________________" << endl;
			cout << "Running Bubble sort " << 5 << " times..." << endl;
			time(&now);
			allComp = 0;
			for (int i = 0; i < 5; i++)
			{
				temp = bubblesort(file_to_read, sort_in, sort_by);
				allComp += temp;
			}
			time(&after);
			dif = difftime(after, now);
			cout << endl << "___Bubble Sort Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif / 5 << " sec" << endl
				<< "Total comparisons: " << allComp << endl
				<< "Average comparisons: " << allComp/5 << endl;

			cout << "_______________________________________" << endl;
			cout << "Running STL sort " << runs << " times..." << endl;
			time(&now);
			for (int i = 0; i < runs; i++)
				stlsort(file_to_read, sort_in, sort_by);
			time(&after);
			dif = difftime(after, now);
			cout << endl << "___STL Sort Analysis___" << endl 
				<< "Run time: " << dif << " sec" <<  endl
				<< "Average run time: " << dif / runs << " sec" << endl;
			select = 6;
			break;
		}
	}
}

double quicksort(string file_name, int s_in, int s_by)
{
	Sort* Qsort = new Sort(file_name, s_in, s_by);
	Qsort->quickSort();
	double totalCount = Qsort->compCount;
	Qsort->~Sort();
	return totalCount;	
}


double mergesort(string file_name, int s_in, int s_by)
{
	Sort* Msort = new Sort(file_name, s_in, s_by);
	Msort->mergeSort();
	double totalCount = Msort->compCount;
	Msort->~Sort();
	return totalCount;
}

double heapsort(string file_name, int s_in, int s_by)
{
	Sort* Hsort = new Sort(file_name, s_in, s_by);
	double totalCount = Hsort->heapSort();
	Hsort->~Sort();
	return totalCount;
}

double bubblesort(string file_name, int s_in, int s_by)
{
	Sort* Bsort = new Sort(file_name, s_in, s_by);
	Bsort->bubbleSort();
	double totalCount = Bsort->compCount;
	Bsort->~Sort();
	return totalCount;
}

void stlsort(string file_name, int s_in, int s_by)
{
	Sort* Ssort = new Sort(file_name, s_in, s_by);
	Ssort->stlsort();
	Ssort->~Sort();
}

