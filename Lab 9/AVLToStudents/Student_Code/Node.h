#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface {

public:

	int data;
	Node* left;
	Node* right;
	int height;

	Node(int value, Node* leftChild = NULL, Node* rightChild = NULL, int tallness = 0) {
		data = value;
		left = leftChild;
		right = rightChild;
		height = tallness;

	}

	int getData(){
		return data;
	}

	NodeInterface * getLeftChild(){
		return left;
	}

	NodeInterface * getRightChild(){
		return right;
	}

	int getHeight(){
		return height;
	}

	void setHeight(int value){
		this->height = value;
	}

	void updateHeight() {
		int LH;
		if (left == NULL)LH = -1;
		else LH = left->height;

		int RH;
		if (right == NULL) RH = -1;
		else RH = right->height;

		height = max(LH, RH) + 1;
	}

	int getBalance() {
		int LH = (left == NULL) ? -1 : left->height;
		int RH = (right == NULL) ? -1 : right->height;

		return RH - LH;
	}

};