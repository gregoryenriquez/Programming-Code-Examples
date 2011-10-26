// ipGen.cpp

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include "miscFunctions.h"
using namespace std;

void generateList()
{
	srand(time(NULL));

	fstream data;
	data.open("outFile.txt", fstream::out);
	string current_line;
	//char temp[10];

	// byte.byte.byte.byte
	char first_byte[4], second_byte[4], third_byte[4], fourth_byte[4];
	cout << "Attempting to insert 9001 IP addresses... " << endl;
	for (int i = 0; i < 9001; i++)
	{
		current_line = "";
		unsigned int num_gen_1 = byteGenerator(); // first byte of IP
		unsigned int num_gen_2 = byteGenerator();
		unsigned int num_gen_3 = byteGenerator();
		unsigned int num_gen_4 = byteGenerator();

		//current_line.append( itoa(i, temp, 10) );
		//current_line.append(": \t");
		current_line.append( itoa(num_gen_1, first_byte, 10) );
		current_line.append(".");
		current_line.append( itoa(num_gen_2, second_byte, 10) );
		current_line.append(".");
		current_line.append( itoa(num_gen_3, third_byte, 10) );
		current_line.append(".");
		current_line.append( itoa(num_gen_4, fourth_byte, 10) );
		current_line.append("\n");
		
		data << current_line;
	}
	
	data.close();
}

unsigned int byteGenerator()
{
	unsigned int temp;
	temp = rand() % 255;
	return temp;
}

