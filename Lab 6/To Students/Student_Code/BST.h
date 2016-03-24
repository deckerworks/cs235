#pragma once

#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
public:
	BST();
	virtual ~BST();
	virtual Node* getRootNode();
	virtual bool add(int data);
	virtual bool remove(int data);
	virtual void clear();
private:
	Node* root;
	bool add_recursive(int data, Node*& current);
	bool remove_recursive(int data, Node*& current);
	bool inorder_predecessor(Node*& n1, Node*& n2);
	void clear_recursive(Node*& root);
	bool find(int value, Node* n);
};