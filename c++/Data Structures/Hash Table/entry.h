// entry.h

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

template <class DataType>
class Node
{
public:
	Node();

	void setDataKey(int k);
	int getDataKey();

	void setDeleted();
	void setNotDeleted();
	bool isDeleted();

	void setDataString(string s);
	string getDataString();

	void setEmpty();
	void setNotEmpty();
	bool isEmpty();

	void setData(DataType d);
	DataType getData();
	
private:
	int dataKey; // sum of 4-byte decimal values
	DataType data; // 32-bit ip address
	bool deleted;
	bool empty;
	string dataString;

};

#endif
