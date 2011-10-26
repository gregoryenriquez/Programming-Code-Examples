//////////////////////////////////////////////
//			heap.h							//
//////////////////////////////////////////////

#ifndef HEAP_H
#define HEAP_H

#include "entry.h"
#include <vector>
using namespace std;

class Heap
{
public:
	Heap(int size);
	~Heap();

	typedef struct node
	{
		string priority;
		Entry e;
	
		node()
		{
			priority = "";
			e = Entry();
		}

	}Node;

	void	swap(int index_1, int index_2);
	void	insert(Entry s);
	Node*	root;
	Entry	deleteMin();
	string	getPriority(Node* n);
	double  allCompare;

	void	percolateUp(int c_index);
	void	percolateDown(int hole_index);
 
	// returns: 0 if ok 
	//			1 if left is less than (swap)
	//			2 if right is less than (swap)
	//			3 if child locations are out of vector bounds
	//			4 if there is only the left child
	//			5 if there are no children
	int		checkChild(int p_index);
	bool	checkBounds(int p_index);

	void	pSwapL(int p_index);
	void	pSwapR(int p_index);
	void	readFile(string filename);
	//void	printHeap();
	void	clearAndPrintSortedHeap();
	int		getCurrent();
	vector<Node*> *heap_table;

private:
	int		table_size;	
	int		current_entries;
	


};

#endif