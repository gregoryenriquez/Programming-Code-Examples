// hashTable.h

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "entry.h"
#include <string>
using namespace std;

template <class DataType>
class HashTable
{
public:
	HashTable(int size);
		
	Node<DataType>* current;

	void	insert(DataType d, string s); // insert->hash data->put into table
	bool	remove(DataType d); // lazy deletion, mark flag 'deleted' to true

	DataType getData(int k); // MANUAL OVERRIDE RETRIEVAL ONLY! (must know key)
	void	setData(int k, DataType d); // MANUAL OVERRIDE INSERTION ONLY! (must know key)

	int		getTableSize(); // return table size
	void processList(string filename);

	void printTable();

	

	unsigned int collisions;
	unsigned int duplicates;
	unsigned int totalEntries;

private:
	int		table_size; // record hash table size
	Node<DataType>*	hash_table; // pointer to the hash table
	int		hashf(string keyString); // hash function

};



#endif