// AVLstudentDB.h

#ifndef AVLSTUDENTDB_H
#define AVLSTUDENTDB_H

#include <iostream>
#include <string>
using namespace std;

class AVLstudentDB
{
public:
	AVLstudentDB(string file_to_read);

	typedef struct node
	{
		string name;
		int key;
		node* left;
		node* right;
		int height;

		node(string n, int k, node* l, node* r, int h)
		{
			name = n;
			key = k;
			left = l;
			right = r;
			height = h;
		}

	}Node;

	Node* root;


	int getH(Node*);
	void insert(int k, string name);

	void readFile(string);
	void inorder();
	void postorder();
	void preorder();
	void Print(Node* n);

	void LR_Rotate(Node* &subroot);
	void LL_Rotate(Node* &subroot);
	void RL_Rotate(Node* &subroot);
	void RR_Rotate(Node* &subroot);
	
private:
	void insert(int k, string name, node* &n);
	void PostfixTraverse(Node* n);
	void InfixTraverse(Node* n);
	void PrefixTraverse(Node* n);

};

#endif