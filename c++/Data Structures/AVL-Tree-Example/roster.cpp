//////////////////////////////////////////
//				roster.cpp				//
//////////////////////////////////////////

#include <string>
#include <iostream>
#include <cmath>
#include "roster.h"
using namespace std;

Roster::Roster()
{
	root = 0;
	current = 0;
	cd = 0;
	//low = 0;
	//high = 20;

}

Roster::~Roster()
{
}

int Roster::count = 0;

void Roster::Add(Student* s, Node* &n)
{
	if (!n)
	{
		n = new node(*s, NULL, NULL, 0);
		if (!root)
		{
			root = n;
			return;
		}
	}

	int key = s->GetID();

	if ( key < n->student_info.GetID() )
	{
		Add(s, n->left);
		if ( getHeight(n->left) - getHeight(n->right) == 2 )
		{
			if ( key < n->left->student_info.GetID() )
			{
				LR_Rotate(n);
			}
			else
				LL_Rotate(n);
		}
	}
	else if ( key > n->student_info.GetID() )
	{
		Add(s, n->right);
		if ( getHeight(n->right) - getHeight(n->left) == 2)
		{
				if ( key > n->right->student_info.GetID() )
				{
					RL_Rotate(n);
				}
				else
				{
					RR_Rotate(n);
				}
		}
	}
	else;
	n->height = max( getHeight(n->left), getHeight(n->right) ) + 1;
}

void Roster::Drop(Node* n, int id)
{

	// lazy delete
	if (n)
	{
		if (n->student_info.GetID() == id)
		{
			n->student_info.SetFirst("");
			n->student_info.SetLast("");
			n->student_info.SetYear("");
		}

		if (n->left)
		{
			Drop(n->left, id);
		}
		if (n->right)
			Drop(n->right, id);
	}
	
	else ;
}
	
void Roster::PostfixTraverse(Node* n)
{
	if (n)
	{
		if (n->left)
			PostfixTraverse(n->left);
		if (n->right)
			PostfixTraverse(n->right);
		Print(n);

	}
}

void Roster::PostFixWrite(Node* n, string& writeOut)
{
	char temp[10];

	if (n)
	{
		if (n->left)
			PostFixWrite(n->left, writeOut);
		if (n->right)
			PostFixWrite(n->right, writeOut);
		writeOut.append( itoa( (n->student_info.GetID() ), temp, 10 ));
		writeOut.append("\t");
		writeOut.append( n->student_info.GetLast() );
		writeOut.append("\t");
		writeOut.append( n->student_info.GetFirst() );
		writeOut.append("\t");
		writeOut.append( n->student_info.GetYear() );
		writeOut.append("\n");
	}
	
}

void Roster::PrefixTraverse(Node* n)
{
	if (n)
	{
		Print(n);
		if (n->left)
			PrefixTraverse(n->left);
		if (n->right)
			PrefixTraverse(n->right);
	}
}

void Roster::InfixTraverse(Node* n)
{
	if (n)
	{
		if (n->left)
		{
			InfixTraverse(n->left);
		}
		Print(n);
		if (n->right)
			InfixTraverse(n->right);
	}
	
	else return;
}

void Roster::Print(Node* n)
{
	n->student_info.PrintInfo();


	cout << "Current height: " << n->height << endl;
	if (n->left)
	{
		cout << "Left of node:";
		n->left->student_info.PrintInfo();
	}
	if (n->right)
	{
		cout << "Right of node:";
		n->right->student_info.PrintInfo();
	}
	
	cout << endl;
}

void Roster::LR_Rotate(Node* &subroot) // rotateWithLeftChild
{
	Node* temp = subroot->left;
	subroot->left = temp->right;
	temp->right = subroot;

	subroot->height = max( getHeight(subroot->left), getHeight(subroot->right) ) +1;
	temp->height = max ( getHeight(temp->left), subroot->height) +1;

	subroot = temp;
/*
	RR_Rotate(subroot->left);
	LL_Rotate(subroot);
*/
}

void Roster::LL_Rotate(Node* &subroot) // doubleLeft
{
	RL_Rotate(subroot->left);
	LR_Rotate(subroot);

/*
	Node* temp = subroot->left;
	subroot->left = temp->right;
	temp->right = subroot;
	subroot->height = max( getHeight(subroot->right), getHeight(subroot->left) ) +1;
	temp->height = max( getHeight(temp->left), getHeight(temp->right) ) + 1;

	subroot = temp;
*/
}

void Roster::RL_Rotate(Node* &subroot) // rotateWithRightChild
{
	Node* temp = subroot->right;
	subroot->right = temp->left;
	temp->left = subroot;

	subroot->height = max (getHeight(subroot->right), getHeight(subroot->left) ) +1;
	temp->height = max (getHeight(temp->right), subroot->height) + 1;

	subroot = temp;
/*
	LL_Rotate(subroot->right);
	RR_Rotate(subroot);
*/
}

void Roster::RR_Rotate(Node* &subroot) // doubleRight
{
	LR_Rotate(subroot->right);
	RL_Rotate(subroot);
/*
	Node* temp = subroot->right;
	subroot->right = temp->left;
	temp->left = subroot;
	subroot->height = max( getHeight(subroot->right), getHeight(subroot->left) ) +1;
	temp->height = max (getHeight(temp->right), getHeight(temp->left) ) + 1;
	subroot = temp;
*/
}

int Roster::getHeight(Node* n)
{
	if (!n) return -1;
	return n->height;
}
