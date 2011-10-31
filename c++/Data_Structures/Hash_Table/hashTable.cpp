// hashTable.cpp

#define QUAD 1
#define LINEAR 0

#include <iostream>
#include "hashTable.h"
#include <fstream>
#include <string>
using namespace std;

template <class DataType>
HashTable<DataType>::HashTable(int size)
{
	hash_table = new Node<DataType>[size];
	table_size = size;
	collisions = 0;
	duplicates = 0;
	totalEntries = 0;
	
	for (int i = 0; i < size; i++)
	{
		current = &hash_table[i];
		current->setDataKey(NULL);
		//current->setData(NULL);
		current->setNotDeleted();
		current->setEmpty();
	}

}
/*
template <class DataType>
int	HashTable<DataType>::convertKeyToInt(string s)
{
	return (int)s;
}
*/
template <class DataType>
void	HashTable<DataType>::insert(DataType d, string s)
{
	int key = hashf(d);
	if (key < 0) key = -key;
	int tries = 100;
	int quad = 1;

	current = &hash_table[key];

#if QUAD
	if (current->isEmpty())
	{
		current->setDataKey(key);
		current->setData(d);
		current->setDataString(s);
		current->setNotEmpty();
		totalEntries++;
	}
	else
	{
		while (!current->isEmpty() && tries > 0)
		{
			collisions++;
			//if (key == table_size-1)
			//	key = 0;
		
			key = key + quad*quad;
			while (key > table_size-1)
			{
				key -= table_size;
			}
			quad++;
			//cout << "Insertion failed, new key: " << key << endl;
			current = &hash_table[key];

			if (current && current->getData() == d)
			{
				duplicates++;
				break;
			}

			tries--;
			if (current && current->isEmpty())
			{
				current->setDataKey(key);
				current->setData(d);
				current->setDataString(s);
				current->setNotEmpty();
				totalEntries++;
				break;
			}
		}
	}
#endif

#if LINEAR
	if (current->isEmpty())
	{
		current->setDataKey(key);
		current->setData(d);
		current->setDataString(s);
		current->setNotEmpty();
		totalEntries++;
	}
	else
	{
		while (!current->isEmpty() && tries > 0)
		{
			collisions++;		
			key++;

			if (key >= table_size-1)
				key = 0;
			//cout << "Insertion failed, new key: " << key << endl;
			current = &hash_table[key];
			if (current && current->getData() == d)
			{
				duplicates++;
				break;
			}

			tries--;
			if (current && current->isEmpty())
			{
				current->setDataKey(key);
				current->setData(d);
				current->setDataString(s);
				current->setNotEmpty();
				totalEntries++;
				break;
			}
		}
	}

#endif
} 

template <class DataType>
bool	HashTable<DataType>::remove(DataType d)
{
	int key = hashf((string) d);
	current = &hash_table[key];
	int tries = 50;

#if LINEAR
	if (current->isEmpty())
	{
		cout << "Data Not Found. \n";
		return false;
	}
	else
	{
		do 
		{
			if (current->getData() == d)
			{
				current->setDataKey(NULL);
				current->setData(NULL);
				current->setDeleted();
			}
			else
			{
				key = key++;
				current = &hash_table[key];
				tries--;
			}
		}while (!current->isEmpty() && tries > 0);
	}
#endif

#if QUAD
	if (current->isEmpty())
	{
		cout << "Data Not Found. \n";
		return false;
	}
	else
	{
		do 
		{
			if (current->getData() == d)
			{
				current->setDataKey(NULL);
				current->setData(NULL);
				current->setDeleted();
			}
			else
			{
				key = key + quad*quad;
				if (key > table_size)
					key = 0;
				quad++;

				current = &hash_table[key];
				tries--;
			}
		}while (!current->isEmpty() && tries > 0);
	}
#endif
}

template <class DataType>
DataType	HashTable<DataType>::getData(int k)
{
	int key = k;
	return hash_table[k].getData();
}

template <class DataType>
void	HashTable<DataType>::setData(int key, DataType d) 
{
	int key = k;
	hash_table[k].setDataKey(key);
	hash_table[k].setData(d);
}

template <class DataType>
int		HashTable<DataType>::getTableSize()
{
	return table_size;
}

template <class DataType>
int		HashTable<DataType>::hashf(DataType d)
{
	//cout << "Data: " << d << endl;
	//cout << "Key: " << d % table_size << endl;
	return (int)(d % table_size);

	//char* cstr;
	//cstr = new char[keyString.size()+1];
	//strcpy(cstr, keyString.c_str());

	// convert char to ascii equivalent
	//int key[2] = { (int)cstr[0], (int)cstr[1] };
	

	//int temp = (key[0]*5 + key[1] * 7) % 199;

	//return temp;
}

template <class DataType>
void	HashTable<DataType>::processList(string filename)
{
	string file_to_open = filename;
	fstream data;
	data.open(file_to_open, fstream::in);

	string temp;
	string current_line;
	string str_ip;
	string stock;
	string str_ip_withdots;
	unsigned int ip;

	
	while (!data.eof())
	{
		getline(data, current_line);
		ip = 0;
		str_ip_withdots = current_line;
		str_ip = "";
		stock = "";

		size_t left = 0, right = 0;

		right = current_line.find_first_of(".");
		temp = current_line.substr(left, right-left);
		stock = temp;
		str_ip.append(temp);

		left = right+1;
		right = current_line.find_first_of(".", left);
		temp = current_line.substr(left, right-left);
		str_ip.append(temp);
		/*
		left = right+1;
		right = current_line.find_first_of(".", left);
		temp = current_line.substr(left, right-left);
		str_ip.append(temp);		

		
		left = right + 1;
		right = current_line.find_first_of("\n");
		temp = current_line.substr(left, right-left);
		str_ip.append(temp);
		*/
		
		
		char* c_str = new char[str_ip.size()+1];
		strcpy(c_str, str_ip.c_str());
		//cout << c_str << "\t" << str_ip << endl; 

		ip = atoi(c_str);
		delete c_str;
		c_str = 0;
		//cout << ip << endl;

		insert(ip, str_ip_withdots);
	}


}

template <class DataType>
void HashTable<DataType>::printTable()
{
	string current_line;
	char temp[20];
	string value;
	fstream data;
	data.open("hash_table.txt", fstream::out);
	for (int i = 0; i < table_size; i++)
	{
		current_line = "";
		current = &hash_table[i];
		current_line.append( itoa((i), temp, 10) );
		current_line.append(",");
		current_line.append( itoa(current->getDataKey(), temp, 10) );
		current_line.append("\t");
		current_line.append( itoa(current->getData(), temp, 10) );
		current_line.append("\t");
		current_line.append( current->getDataString() );
		current_line.append("\t");
		current_line.append("\t");
		current_line.append("\tDeleted: ");

		value = current->isDeleted() ? "1" : "0";
		current_line.append( value );

		current_line.append("\tEmpty: ");

		value = current->isEmpty() ? "1" : "0";
		current_line.append( value );
		current_line.append("\n");
		data << current_line;
	}
	data.close();
	cout << "Total number of collisions: " << collisions << endl;
	cout << "Total number of IP addresses entered of 9001 attempts: " << totalEntries << endl;
	cout << "Total number of duplicates found: " << duplicates << endl;
}