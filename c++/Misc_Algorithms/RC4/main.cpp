/*
*	filename: main.cpp
*
*
*/

#include <iostream>
#include <string>
using namespace std;

char hexToChar(string s);
string charToHex(unsigned char c);
void printS(unsigned char keyPrint[], int size);

int main()
{
	bool Dump = false;
	int keyStreamLength = 1001;
	const int arraySize = 256;
	unsigned char K[arraySize];
	unsigned char S[arraySize];
	int temp_i, temp_j;

	int N = 7;
	const int keySize = 7;
	string keyString[keySize] = { "0x1A", "0x2B", "0x3C", "0x4D", "0x5E", "0x6F", "0x77" };
	

	unsigned char key[keySize];
	
	for (int i = 0; i < keySize; i++)
	{
		key[i] = hexToChar(keyString[i]);
		cout << key[i];
	}

	// key = 0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x77
	//dkey = 26,     43,   60,   77,   94,  111,  119
	for (int i = 0; i < 256; i++)
	{
		S[i] = (unsigned char)i;
		K[i] = key[i % N];
	}

	printS(S, arraySize);

	for (int i = 0, j = 0; i < 256; i++)
	{
		j = (j + (unsigned int)S[i] + (unsigned int)K[i]) % 256;
		swap(S[i], S[j]);
		temp_i = i;
		temp_j = j;
	}
	
	cout << "\nAfter Initialization...\n";
	cout << "i value = " << temp_i << endl;
	cout << "j value = " << temp_j << endl;

	printS(S, arraySize);

	string keyStream;
	char* temp;
	char keyStreamByte;
	temp = &keyStreamByte;
	int index = 0;
	int counter = 0;
	for (int i = 0, j = 0; i < keyStreamLength; i++)
	{
		temp_i = i;
		temp_j = j;
		if (counter == 100)
		{
			cout << "\nAfter first " << counter << " bytes\n";
			cout << "i value = " << temp_i << endl;
			cout << "j value = " << temp_j << endl;
			printS(S, arraySize);
		}
		if (counter == 1000)
		{
			cout << "\nAfter first " << counter << " bytes\n";
			cout << "i value = " << temp_i << endl;
			cout << "j value = " << temp_j << endl;
			printS(S, arraySize);
		}

		i = (i+1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i], S[j]);
		index = ((int)S[i] + (int)S[j]) % 256;
		keyStreamByte = S[index];
		//cout << keyStreamByte;
		keyStream.append(temp);
		
		counter++;
	}
	
	char finish;
	cin >> finish;
	return 0;
}

char hexToChar(string s)
{ // 0xhh
	char converted;
	char highOrderHex = s[2];
	char lowOrderHex = s[3];

	int highOrderInt = (int)highOrderHex;
	int lowOrderInt = (int)lowOrderHex;

	if (highOrderInt >= 97 && highOrderInt <= 122)
		highOrderInt = highOrderInt - 32;

	if (lowOrderInt >= 97 && lowOrderInt <= 122)
		lowOrderInt = lowOrderInt - 32;

	if (highOrderInt >= 65 && highOrderInt <= 90)
	{ // A-Z
		highOrderInt = highOrderInt - 55;
	}
	else
	{ // 0-9
		highOrderInt = highOrderInt - 48;
	}

	if (lowOrderInt >= 65 && lowOrderInt <= 90)
	{
		lowOrderInt = lowOrderInt - 55;
	}
	else
	{
		lowOrderInt = lowOrderInt - 48;
	}

	converted = (char) (highOrderInt*16 + lowOrderInt);

	return converted;
}

string charToHex(unsigned char c)
{
	string temp = "0xZZ";
	int charIntValue = (int)c;
	int highOrderInt = charIntValue / 16;
	int lowOrderInt = charIntValue % 16;
	char highOrderHex, lowOrderHex;
	
	if (highOrderInt >= 0 && highOrderInt <= 9)
	{
		highOrderHex = (char)(highOrderInt + 48);
	}
	else
	{
		highOrderHex = (char)(highOrderInt + 55);
	}

	if (lowOrderInt >= 0 && lowOrderInt <= 9)
	{
		lowOrderHex = (char)(lowOrderInt + 48);
	}
	else
	{
		lowOrderHex = (char)(lowOrderInt + 55);
	}

	temp[2] = highOrderHex;
	temp[3] = lowOrderHex;

	return temp;
}

void printS(unsigned char keyPrint[], int size)
{
	cout << endl;
	string temp;
	const int rowLength = 16;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		temp = charToHex(keyPrint[i]);
		cout << temp << " ";

		if (counter == rowLength)
		{
			cout << endl;
		}
	}
}