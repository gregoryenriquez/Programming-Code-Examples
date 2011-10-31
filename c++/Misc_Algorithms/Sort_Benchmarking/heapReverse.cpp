//////////////////////////////////////////////
//			heap.cpp							//
//////////////////////////////////////////////

#include "heapReverse.h"
#include "entry.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

HeapReverse::HeapReverse(int size)
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

HeapReverse::~HeapReverse()
{
	delete heap_table;
}

int	HeapReverse::getCurrent()
{
	return current_entries;
}

void	HeapReverse::insert(Entry s)
{
	Node* temp = new Node();
	temp->priority = s.comparable;
	temp->e = s;

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

void	HeapReverse::percolateUp(int c_index)
{
	int parent = c_index / 2;
	int pos = checkChild(parent);
	if (pos == 4 && 
		(heap_table->at(parent)->priority < heap_table->at(c_index)->priority))
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

Entry	HeapReverse::deleteMin()
{
	Entry temp = heap_table->at(1)->e;
	swap(1, current_entries);
	heap_table->at(current_entries) = NULL;
	percolateDown(1);

	current_entries--;
	return temp;
}

void	HeapReverse::swap(int index_1, int index_2)
{
	Node* temp = heap_table->at(index_1);
	heap_table->at(index_1) = heap_table->at(index_2);
	heap_table->at(index_2) = temp;
}

void	HeapReverse::percolateDown(int hole_index)
{
	if (hole_index*2 > table_size)
		return;
	if (heap_table->at(hole_index*2) == NULL)
		return;

	if (heap_table->at(hole_index*2) && !heap_table->at(hole_index*2+1))
	{
			pSwapL(hole_index);
	}
	else if (heap_table->at(hole_index*2)->priority > heap_table->at(hole_index*2+1)->priority)
	{
		pSwapL(hole_index);
		percolateDown(hole_index*2);
	}
	else if (heap_table->at(hole_index)->priority < heap_table->at(hole_index*2+1)->priority)
	{
		pSwapR(hole_index);
		percolateDown(hole_index*2+1);
	}
	else
		return;
}

int		HeapReverse::checkChild(int p_index)
{
	int temp = 0;
	if (!checkBounds(p_index))
		return 3;
	
	if (heap_table->at(p_index*2) == NULL)
		return 5;

	if (heap_table->at(p_index*2+1) == NULL)
		return 4;

	if (heap_table->at(p_index*2)->priority > heap_table->at(p_index)->priority)
		temp = 1;

	if (heap_table->at(p_index*2+1)->priority > heap_table->at(p_index)->priority)
	{
		temp = 2;
		if (heap_table->at(p_index*2)->priority > heap_table->at(p_index*2+1)->priority)
			temp = 1;
	}

	return temp;

}

bool	HeapReverse::checkBounds(int p_index)
{
		if (p_index*2 > table_size)
			return false;

		return true;
}

void	HeapReverse::pSwapL(int p_index)
{
	Node* temp = heap_table->at(p_index);
	heap_table->at(p_index) = heap_table->at(p_index*2);
	heap_table->at(p_index*2) = temp;
}

void	HeapReverse::pSwapR(int p_index)
{
	Node* temp = heap_table->at(p_index);
	heap_table->at(p_index) = heap_table->at(p_index*2 + 1);
	heap_table->at(p_index*2 + 1) = temp;
}

void	HeapReverse::readFile(string filename)
{
	fstream data;
	data.open(filename, fstream::in);

	string current_line;

	while (getline(data, current_line))
	{
		string priority = "";
		string symbol = "";
		string name = "";
		char* c_str;

		size_t left = 0, right = 0;

		right = current_line.find_first_of(",");
		priority = current_line.substr(left, right - left);

		left = right+2;
		right = current_line.find_first_of("\n", left);
		name = current_line.substr( left, right - left);

		Entry temp_student = Entry(symbol, name);
		insert(temp_student);
	}

	data.close();
}



void	HeapReverse::clearAndPrintSortedHeap()
{
	while (current_entries > 0)
	{
		Entry s = deleteMin();
		//cout << s.getP() << "\t" << s.getLast() << "\t" << s.getFirst()
		//	<< "\t" << s.getYear() << endl;
		
	}
}