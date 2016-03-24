#include "Node.h"

Node::Node(int data) {
	this->left_child = NULL;
	this->right_child = NULL;
	this->data = data;
}

Node::~Node() {

}

int Node::getData() {
	return data;
}

Node* Node::getLeftChild() {
	return left_child;
}

Node* Node::getRightChild() {
	return right_child;
}