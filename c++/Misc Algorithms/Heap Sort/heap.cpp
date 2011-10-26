//////////////////////////////////////////////
//			heap.cpp							//
//////////////////////////////////////////////

#include "heap.h"
#include "student.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Heap::Heap(int size)
{
	heap_table = new vector<Node*>(size);
	heap_table->at(0) = 0;
	table_size = size;
	current_entries = 0;
	root = 0;
	for (int i = 0; i < size; i++)
	{
		heap_table->at(i) = NULL;
	}
}

Heap::~Heap()
{
	delete heap_table;
}

void	Heap::insert(Student s)
{
	Node* temp = new Node();
	temp->priority = s.getP();
	temp->s = s;

	if (current_entries+1 == table_size)
	{
		heap_table->resize(table_size*2, NULL);
		table_size = table_size*2;
	}
	if (current_entries == 0)
	{
		heap_table->at(1) = temp;
		root = heap_table->at(1);
	}
		
	else
	{
		heap_table->at(current_entries+1) = temp;
		percolateUp(current_entries+1);
	}
	current_entries++;
}

void	Heap::percolateUp(int c_index)
{
	int parent = c_index / 2;
	int pos = checkChild(parent);
	if (pos == 4 && 
		(heap_table->at(parent)->priority > heap_table->at(c_index)->priority))
	{	
			pSwapL(parent);
			if (parent == 1) return;
			percolateUp(parent);
		
	}
	else if (pos == 1)
	{
		pSwapL(parent);
		if (parent == 1) return;
		percolateUp(parent);
	}
	else if (pos == 2)
	{
		pSwapR(parent);
		if (parent == 1) return;
		percolateUp(parent);
	}

	return;
}

Student	Heap::deleteMin()
{
	Student temp = heap_table->at(1)->s;
	swap(1, current_entries);
	heap_table->at(current_entries) = NULL;
	percolateDown(1);

	

	/*
	// scan list for hole in wrong position
	for (int i = 1; i < current_entries+1; i++)
	{
		if (heap_table->at(i)->priority == 1000)
		{
			heap_table->at(i) = heap_table->at(current_entries);
			percolateUp(i);
			heap_table->at(current_entries) = NULL;
			break;
		}
	}
	*/
	current_entries--;
	return temp;
}

void	Heap::swap(int index_1, int index_2)
{
	Node* temp = heap_table->at(index_1);
	heap_table->at(index_1) = heap_table->at(index_2);
	heap_table->at(index_2) = temp;
}

void	Heap::percolateDown(int hole_index)
{
	if (hole_index*2 > table_size)
		return;
	if (heap_table->at(hole_index*2) == NULL)
		return;

	if (heap_table->at(hole_index*2) && !heap_table->at(hole_index*2+1))
	{
			pSwapL(hole_index);
	}
	else if (heap_table->at(hole_index*2)->priority < heap_table->at(hole_index*2+1)->priority)
	{
		pSwapL(hole_index);
		percolateDown(hole_index*2);
	}
	else if (heap_table->at(hole_index)->priority > heap_table->at(hole_index*2+1)->priority)
	{
		pSwapR(hole_index);
		percolateDown(hole_index*2+1);
	}
	else
		return;
}

int		Heap::checkChild(int p_index)
{
	int temp = 0;
	if (!checkBounds(p_index))
		return 3;
	
	if (heap_table->at(p_index*2) == NULL)
		return 5;

	if (heap_table->at(p_index*2+1) == NULL)
		return 4;

	if (heap_table->at(p_index*2)->priority < heap_table->at(p_index)->priority)
		temp = 1;

	if (heap_table->at(p_index*2+1)->priority < heap_table->at(p_index)->priority)
	{
		temp = 2;
		if (heap_table->at(p_index*2)->priority < heap_table->at(p_index*2+1)->priority)
			temp = 1;
	}

	return temp;

}

bool	Heap::checkBounds(int p_index)
{
		if (p_index*2 > table_size)
			return false;

		return true;
}

void	Heap::pSwapL(int p_index)
{
	Node* temp = heap_table->at(p_index);
	heap_table->at(p_index) = heap_table->at(p_index*2);
	heap_table->at(p_index*2) = temp;
}

void	Heap::pSwapR(int p_index)
{
	Node* temp = heap_table->at(p_index);
	heap_table->at(p_index) = heap_table->at(p_index*2 + 1);
	heap_table->at(p_index*2 + 1) = temp;
}

void	Heap::readFile(string filename)
{
	fstream data;
	data.open(filename, fstream::in);

	string current_line;

	while (getline(data, current_line))
	{
		int priority = 0;
		string last = "";
		string first = "";
		string year = "";
		string temp = "";
		char* c_str;

		size_t left = 0, right = 0;

		right = current_line.find_first_of(",");
		temp = current_line.substr(left, right - left);
		c_str = new char[temp.size()+1];
		strcpy(c_str, temp.c_str());

		priority = atoi(c_str);

		left = right+2;
		right = current_line.find_first_of(",", left);
		last = current_line.substr( left, right - left);

		left = right+2;
		right = current_line.find_first_of(",", left);
		first = current_line.substr(left, right - left);

		left = right+2;
		right = current_line.find_first_of("\n", left);
		year = current_line.substr( left, right - left);

		Student temp_student = Student(priority, last, first, year);
		insert(temp_student);
	}

	data.close();
}

void	Heap::printHeap()
{
	for (int i = 1; i < current_entries; i++)
	{
		cout << heap_table->at(i)->s.getP() << "\t";
		cout << heap_table->at(i)->s.getLast() << "\t";
		cout << heap_table->at(i)->s.getFirst() << "\t";
		cout << heap_table->at(i)->s.getYear() << endl;
	}
}

void	Heap::clearAndPrintSortedHeap()
{
	while (current_entries > 0)
	{
		Student s = deleteMin();
		cout << s.getP() << "\t" << s.getLast() << "\t" << s.getFirst()
			<< "\t" << s.getYear() << endl;
		
	}
}