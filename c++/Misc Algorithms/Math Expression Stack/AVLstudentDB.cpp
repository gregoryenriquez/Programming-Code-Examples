// AVLstudentDB.cpp

#include "AVLstudentDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


AVLstudentDB::AVLstudentDB(string file_to_read)
{
	root = 0;
	readFile(file_to_read);
	
	
}


void AVLstudentDB::insert(int k, string name)
{
	insert(k, name, root);
}


//		node(string n, int k, node* l, node* r, int h)
void AVLstudentDB::insert(int k, string name, node* &n)
{
	if (!n)
	{
			n = new node(name, k, NULL, NULL, 0);
			if (!root)
			{
				root = n;
				return;
			}
	}

	int key = k;

	if ( key < n->key )
	{
		insert(key, name, n->left);
		if ( getH(n->left) - getH(n->right) == 2)
		{
			if (key < n->left->key)
			{
				LL_Rotate(n);
			}
			else
				LR_Rotate(n);
		}
	}
	else if ( key > n->key)
	{
		insert(k, name, n->right);
		if ( getH(n->right) - getH(n->left) == 2)
		{
			if (key > n->right->height)
			{
				RR_Rotate(n);
			}
			else
				RL_Rotate(n);
		}
	}
	else;
	n->height = max(getH(n->left), getH(n->right) )+1;
}



void AVLstudentDB::readFile(string file)
{

	fstream data;
	data.open(file, fstream::in | fstream::out);

	string current_line;
	while (getline(data, current_line) )
	{
		int read_id;
		string name;
		string temp;
		char* c_str;

		size_t left = 0, right = 0;

		right = current_line.find_first_of(" ");
		temp = current_line.substr(left, right-left);
		c_str = new char[temp.size()+1];
		strcpy(c_str, temp.c_str());

		read_id = atoi(c_str);

		left = right+1;

		right = current_line.find_first_of("\n", left);
		name = current_line.substr(left, right-left);

		insert(read_id, name);

	}
	data.close();
}

int AVLstudentDB::getH(Node* n)
{
	if (!n) return -1;
	return n->height;
}

void AVLstudentDB::LR_Rotate(Node* &subroot) 
{
	RR_Rotate(subroot->left);
	LL_Rotate(subroot);

}

void AVLstudentDB::LL_Rotate(Node* &subroot) 
{
	Node* temp = subroot->left;
	subroot->left = temp->right;
	temp->right = subroot;
	subroot->height = max( getH(subroot->right), getH(subroot->left) ) +1;
	temp->height = max( getH(temp->left), getH(temp->right) ) + 1;

	subroot = temp;


}

void AVLstudentDB::RL_Rotate(Node* &subroot)
{
	LL_Rotate(subroot->right);
	RR_Rotate(subroot);

}

void AVLstudentDB::RR_Rotate(Node* &subroot) 
{
	Node* temp = subroot->right;
	subroot->right = temp->left;
	temp->left = subroot;
	subroot->height = max( getH(subroot->right), getH(subroot->left) ) +1;
	temp->height = max (getH(temp->right), getH(temp->left) ) + 1;
	subroot = temp;


}

void AVLstudentDB::postorder()
{
	PostfixTraverse(root);
}

void AVLstudentDB::inorder()
{
	InfixTraverse(root);
}

void AVLstudentDB::preorder()
{
	PrefixTraverse(root);
}

void AVLstudentDB::PrefixTraverse(Node* n)
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


void AVLstudentDB::PostfixTraverse(Node* n)
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

void AVLstudentDB::Print(Node* n)
{
	string name = n->name;
	//int id = n->key;

	cout << "Name: " << name << endl;
	cout << "Current height: " << n->height << endl;
	if (n->left)
	{
		cout << "Left of node:";
		cout << n->left->name << endl;
	}
	if (n->right)
	{
		cout << "Right of node:";
		cout << n->right->name << endl;
	}
	
	cout << endl;
}

void AVLstudentDB::InfixTraverse(Node* n)
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
