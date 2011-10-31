// entry.cpp

#include <iostream>
#include "entry.h"
using namespace std;

template <class DataType>
Node<DataType>::Node()
{
}

template <class DataType>
void	Node<DataType>::setDataKey(int k)
{
	dataKey = k;
}

template <class DataType>
void	Node<DataType>::setDataString(string s)
{
	dataString = s;
}

template <class DataType>
string	Node<DataType>::getDataString()
{
	return dataString;
}

template <class DataType>
int	Node<DataType>::getDataKey()
{
	return dataKey;
}

template <class DataType>
void	Node<DataType>::setDeleted()
{
	deleted = true;
}

template <class DataType>
void Node<DataType>::setNotDeleted()
{
	deleted = false;
}

template <class DataType>
void Node<DataType>::setNotEmpty()
{
	empty = false;
}

template <class DataType>
bool	Node<DataType>::isDeleted()
{
	return deleted;
}
	
template <class DataType>
void	Node<DataType>::setEmpty()
{
	empty = true;
}

template <class DataType>
bool	Node<DataType>::isEmpty()
{
	return empty;
}

template <class DataType>
void	Node<DataType>::setData(DataType d)
{
	data = d;
}

template <class DataType>
DataType	Node<DataType>::getData()
{
	return data;
}
