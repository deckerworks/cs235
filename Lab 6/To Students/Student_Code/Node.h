#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface
{
public:
	Node (int data);
	virtual ~Node ();
	virtual int getData();
	virtual Node * getLeftChild();
	virtual Node * getRightChild();
	
	Node * left_child;
	Node * right_child;
	int data;
};