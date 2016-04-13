#pragma once

#include "AVLInterface.h"
#include "Node.h"

class AVL : public AVLInterface {
public:

	AVL();
	~AVL();

	virtual NodeInterface * getRootNode();
	virtual Node* recAdd(Node* curr, int value);
	virtual bool contains(int value);
	virtual bool recContains(Node* curr, int value);
	virtual bool add(int data);

	Node* IOP(Node* curr, Node* rNode);

	Node* recRemove(Node* curr, int x);

	void rotateRR(Node* a, Node* b);
	void rotateRL(Node* a, Node* b, Node* c);
	void rotateLL(Node* a, Node* b);
	void rotateLR(Node* a, Node* b, Node* c);
	virtual bool remove(int data);
	virtual void clear();
	virtual int size();
	virtual Node* balance(Node* node);

};
