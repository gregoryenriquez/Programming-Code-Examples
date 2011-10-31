//////////////////////////////////////////
//				roster.h				//
//////////////////////////////////////////
#include <string>
#include <iostream>
#include "student.h"
using namespace std;

#ifndef ROSTER_H
#define ROSTER_H

class Roster
{
public:
	Roster();
	~Roster();

	typedef struct node
	{
		Student student_info;
		node* left;
		node* right;
		int height;
		//int depth;

		node(Student s, node* l, node* r, int h)
		{
			student_info = s;
			left = l;
			right = r;
			height = h;
		}

	}Node;
	static int count;
	int low; // depth
	int high; // depth
	//int ch; // current height
	int cd; // current depth

	Node* current;
	Node* root;

	int getHeight(Node* n);

	void Add(Student* s, Node* &n);

	void Drop(Node* n, int id);

	void PostFixWrite(Node* n, string& writeOut);
	void PostfixTraverse(Node* n);
	void PrefixTraverse(Node* n);
	void InfixTraverse(Node* n);
	void Print(Node* n);

	//void BalanceCheck(Node* n, int depth);

	void LR_Rotate(Node* &subroot);
	void LL_Rotate(Node* &subroot);
	void RL_Rotate(Node* &subroot);
	void RR_Rotate(Node* &subroot);

private:


};

#endif