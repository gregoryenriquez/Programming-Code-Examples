/////////////
// allsort.h
/////////////

#ifndef ALLSORT_H
#define ALLSORT_H

#include <iostream>
#include <string>
#include <vector>
#include "entry.h"
#include "heap.h"
#include "miscFunctions.h"
using namespace std;

class Sort
{
public:
	Sort(string s, int asc, int c);
	~Sort();
	typedef struct node
	{
		string value;
		Entry valuedata;

		node(string v, Entry d)
		{
			value = v;
			valuedata = d;
		}

	}Node;

	void quickSort();
	void mergeSort();
	double heapSort();
	void bubbleSort();
	void stlsort();
	void readFile();
	double compCount;

private:
	string file_to_read;
	int ascending;
	int col;
	vector<Node*> *svec;
	int findMid(string f, string m, string l);

	void quickSort(int front, int back);
	void quickSortReverse(int front, int back);
	void mergeSort(vector<Node*> &msvec, int front, int back);
	void mergeSortReverse(vector<Node*> &msvec, int front, int back);
	void merge(vector<Node*> &msvec, int front, int mid, int back);
	void mergeReverse(vector<Node*> &msvec, int front, int mid, int back);
	void bubbleSort(int index);
	void bubbleSortReverse(int index);
	void stlsortForward();
	void stlsortReverse();
	double heapSortForward();
	double heapSortReverse();


};

#endif
