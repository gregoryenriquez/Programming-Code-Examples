/////////////
// allsort.cpp
/////////////

#include "allsort.h"
#include "heap.h"
#include "heapReverse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;

Sort::Sort(string s, int asc, int c)
{
	file_to_read = s;
	ascending = asc;
	col = c;
	svec = new vector<Node*>();
	readFile();
	compCount = 0;
}

Sort::~Sort()
{
	svec->clear();
	delete svec;

}

void Sort::readFile()
{
	fstream file;
	file.open(file_to_read, fstream::in);

	string current_line;
	string symbol, name;

	while (getline(file, current_line))
	{
		symbol = "";
		name = "";

		size_t left = 0, right = 0;

		right = current_line.find_first_of(",");
		symbol = current_line.substr(left, right-left);
		
		left = right+1;
		right = current_line.find_first_of("\n", left);
		name = current_line.substr(left, right-left);

		Entry* temp = new Entry(symbol, name);
		Node* temp_node;
		if (col == 2)
			temp_node = new node(temp->getName(), (*temp));
		else
			temp_node = new node(temp->comparable, (*temp));
		svec->push_back(temp_node);
		delete temp;
		
		
	}

	file.close();
}

void Sort::quickSort()
{
	if (ascending == 2)
		quickSortReverse(0, svec->size()-1);
	else
		quickSort(0, svec->size()-1 );
	
}

void Sort::quickSortReverse(int front, int back)
{
	if (front == back) return;
	string first, mid, last;
	first = svec->at(front)->value;
	last = svec->at(back)->value;
	mid = svec->at( (back-front)/2 )->value;
	int pos = findMid(first, mid, last);
	if ( pos == 1 )
	{
		swap( svec->at(front), svec->at(back) );
	}
	else if ( pos == 2 )
	{
		swap( svec->at( (back-front)/2 ), svec->at(back) );
	}

	int left = front, right = back-1; 
	string pivot = svec->at(back)->value;

	while (left != right)
	{
		while (svec->at(left)->value >= pivot && !(left == right))
		{
			compCount++;
			left++;
			if (left == right) break;
		}
		while (svec->at(right)->value < pivot && !(left == right))
		{
			compCount++;
			right--;
			if (left == right) break;
		}
		swap(svec->at(left), svec->at(right));
	}
	swap(svec->at(right), svec->at(back));
	if (front == back) return;

	quickSortReverse(front, right);
	quickSortReverse(right+1, back);
	return;
}

void Sort::quickSort(int front, int back)
{
	if (front == back) return;
	string first, mid, last;
	first = svec->at(front)->value;
	last = svec->at(back)->value;
	mid = svec->at( (back-front)/2 )->value;
	int pos = findMid(first, mid, last);
	if ( pos == 1 )
	{
		swap( svec->at(front), svec->at(back) );
	}
	else if ( pos == 2 )
	{
		swap( svec->at( (back-front)/2 ), svec->at(back) );
	}

	int left = front, right = back-1; 
	string pivot = svec->at(back)->value;

	while (left != right)
	{
		while (svec->at(left)->value <= pivot && !(left == right))
		{
			compCount++;
			left++;
			if (left == right) break;
		}
		while (svec->at(right)->value > pivot && !(left == right))
		{
			compCount++;
			right--;
			if (left == right) break;
		}
		swap(svec->at(left), svec->at(right));
	}
	swap(svec->at(right), svec->at(back));
	if (front == back) return;

	quickSort(front, right);
	quickSort(right+1, back);
	return;
}

int Sort::findMid(string f, string m, string l)
{
	if (f >= m && f <= l) {compCount++; return 1;}
	else if (f >= l && f <= m) {compCount++; return 1;}
	else if (m >= l && m <= f) {compCount++; return 2;}
	else if (m >= f && m <= l) {compCount++; return 2;}
	else return 3;	
}

void Sort::mergeSort()
{
	if (ascending == 2)
		mergeSortReverse((*svec), 0, svec->size()-1);
	else
		mergeSort((*svec), 0, svec->size()-1);
}

void Sort::mergeSortReverse(vector<Node*> &msvec, int front, int back)
{
	int mid = (front+back) / 2;
	if (front < back)
	{
		mergeSortReverse(*svec, front, mid);
		mergeSortReverse(*svec, mid+1, back);
		mergeReverse(*svec, front, mid, back);
	}

}

void Sort::mergeReverse(vector<Node*> &msvec, int front, int mid, int back)
{
	// initialize two dummy nodes that act as sentinels
	Entry* edummy = new Entry("", "");
	Node* dummy = new Node("AAAAAA", *edummy);
	int n1 = mid - front + 1;
	int n2 = back - mid;
	int i = 0, j = 0;
	vector<Node*>* left = new vector<Node*>(n1+1);
	vector<Node*>* right = new vector<Node*>(n2+1);
	for (i = 0; i < n1; i++)
	{
		left->at(i) = msvec.at(front+i);
	}
	for (j = 0; j < n2; j++)
	{
		right->at(j) = msvec.at(mid+j+1);
	}
	i = 0; 
	j = 0;
	left->at(n1) = dummy;
	right->at(n2) = dummy;

	for (int k = front; k <= back; k++)
	{
		compCount++;
		if (left->at(i)->value >= right->at(j)->value)
		{
		
			msvec.at(k) = left->at(i);
			i++;
		}
		else 
		{
			msvec.at(k) = right->at(j);
			j++;
		}
	}
	delete left;
	delete right;
	delete dummy;
	delete edummy;

}

void Sort::mergeSort(vector<Node*> &msvec, int front, int back)
{
	int mid = (front+back) / 2;
	if (front < back)
	{
		mergeSort(*svec, front, mid);
		mergeSort(*svec, mid+1, back);
		merge(*svec, front, mid, back);
	}

}

void Sort::merge(vector<Node*> &msvec, int front, int mid, int back)
{
	// initialize two dummy nodes that act as sentinels
	Entry* edummy = new Entry("", "");
	Node* dummy = new Node("ZZZZZ", *edummy);
	int n1 = mid - front + 1;
	int n2 = back - mid;
	int i = 0, j = 0;
	vector<Node*>* left = new vector<Node*>(n1+1);
	vector<Node*>* right = new vector<Node*>(n2+1);
	for (i = 0; i < n1; i++)
	{
		left->at(i) = msvec.at(front+i);
	}
	for (j = 0; j < n2; j++)
	{
		right->at(j) = msvec.at(mid+j+1);
	}
	i = 0; 
	j = 0;
	left->at(n1) = dummy;
	right->at(n2) = dummy;

	for (int k = front; k <= back; k++)
	{
		compCount++;
		if (left->at(i)->value <= right->at(j)->value)
		{
			msvec.at(k) = left->at(i);
			i++;
		}
		else 
		{
			msvec.at(k) = right->at(j);
			j++;
		}
	}
	delete left;
	delete right;
	delete dummy;
	delete edummy;

}

double Sort::heapSort()
{
	double temp;
	if (ascending == 2)
		temp = heapSortReverse();
	else
		temp = heapSortForward();
	return temp;
}

double Sort::heapSortForward()
{
	int entries_to_insert = svec->size();
	Heap *heap_vec = new Heap(1);
		
	for (int i = 0; i < entries_to_insert; i++)
	{
		if (col == 2)
			svec->at(i)->valuedata.comparable = svec->at(i)->valuedata.getName();
		
			heap_vec->insert(svec->at(i)->valuedata);
	}

	for (int i = 0; i < entries_to_insert; i++)
	{
		svec->at(i)->valuedata = heap_vec->deleteMin();
		svec->at(i)->value = svec->at(i)->valuedata.comparable;
	}
	//cout << "Total comparisons: " << heap_vec->allCompare << endl;
	double temp = heap_vec->allCompare;
	heap_vec->heap_table->clear();
	delete heap_vec;
	return temp;
}

double Sort::heapSortReverse()
{
	int entries_to_insert = svec->size();
	HeapReverse *heap_vec = new HeapReverse(1);
		
	for (int i = 0; i < entries_to_insert; i++)
	{
		if (col == 2)
		svec->at(i)->valuedata.comparable = svec->at(i)->valuedata.getName();
		heap_vec->insert(svec->at(i)->valuedata);
	}

	for (int i = 0; i < entries_to_insert; i++)
	{
		svec->at(i)->valuedata = heap_vec->deleteMin();
		svec->at(i)->value = svec->at(i)->valuedata.comparable;
	}
	heap_vec->heap_table->clear();
	delete heap_vec;
	return 47534;
}

void Sort::bubbleSort()
{


	for (int j = 0; j < svec->size()-1; j++)
	{
		for (int i = 0; i < svec->size()-1; i++)
		{
			if (ascending == 2)
				bubbleSortReverse(i);
			else
				bubbleSort(i);
		}
	}
}

void Sort::bubbleSort(int index)
{	
	if (svec->at(index+1)->value < svec->at(index)->value)
	{
		compCount++;
		swap(svec->at(index+1), svec->at(index));
	}
}

void Sort::bubbleSortReverse(int index)
{
	if (svec->at(index+1)->value > svec->at(index)->value)
		swap(svec->at(index+1), svec->at(index));
}

void Sort::stlsort()
{
	if (ascending == 2)
		stlsortReverse();
	else
		stlsortForward();
}

void Sort::stlsortForward()
{
	struct myclass {
		  bool operator() (Node* i,Node* j) { return (i->value<j->value);}
	} myobject;
	sort(svec->begin(), svec->end(), myobject);

}

void Sort::stlsortReverse()
{
	struct myclass {
		  bool operator() (Node* i,Node* j) { return (i->value>j->value);}
	} myobject;
	sort(svec->begin(), svec->end(), myobject);

}


