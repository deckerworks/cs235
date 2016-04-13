#include "AVL.h"
#include "Node.h"

int size_of_tree = 0;

Node* root = NULL;

AVL::AVL(){
	root = NULL;
}
AVL::~AVL(){
	clear();
}

NodeInterface * AVL::getRootNode(){
	return root;
}

int AVL::size(){
	return size_of_tree;
}

bool AVL::recContains(Node* curr, int value){

	bool contains = false;

	if (curr == NULL){
		return false;
	}

	if (value == curr->data) {
		contains = true;
	}
	else if (value < curr->data){
		contains = recContains(curr->left, value);
	}
	else if (value > curr->data){
		contains = recContains(curr->right, value);
	}
	else {
		contains = false;
	}
	return contains;
}

bool AVL::contains(int value){

	if (root == NULL) {
		return false;
	}
	else {
		bool contains = recContains(root, value);
		return contains;
	}
}

// recursively add
Node* AVL::recAdd(Node* c, int x){

	if (c == NULL){
		return new Node(x);
	}
	else if (x < c->data){
		c->left = recAdd(c->left, x);
		return balance(c);
	}
	else if (x > c->data){
		c->right = recAdd(c->right, x);
		return balance(c);
	}
}

void AVL::rotateRR(Node* a, Node* b) {
	a->right = b->left;
	b->left = a;

	a->updateHeight();
	b->updateHeight();
}

void AVL::rotateRL(Node* a, Node* b, Node* c) {
	a->right = c;
	b->left = c->right;
	c->right = b;

	rotateRR(a, c);

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();
}

void AVL::rotateLL(Node* a, Node* b) {
	a->left = b->right;
	b->right = a;

	a->updateHeight();
	b->updateHeight();
}

void AVL::rotateLR(Node* a, Node* b, Node* c) {
	a->left = c;
	b->right = c->left;
	c->left = b;

	rotateLL(a, c);

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();
}

Node* AVL::balance(Node* a){
	
	if (a == NULL) return NULL;
	a->updateHeight();

	if (a->getBalance() > 1) {
		// RR or RL case
		Node* b = a->right;

		if (b->getBalance() < 0) {
			Node* c = b->left;
			rotateRL(a, b, c);
			return c;
		} 
		else {
			rotateRR(a, b);
			return b;
		}
	} 
	else if (a->getBalance() < -1) {
		// LL or LR case
		Node* b = a->left;

		if (b->getBalance() > 0) {
		 	Node* c = b->right;
			rotateLR(a, b, c);
			return c;
		} 
		else {
			rotateLL(a, b);
			return b;
		}
	} 
	else {
		return a;
	}
}

bool AVL::add(int x){
	if (x == 2){
	}

	if (!(contains(x))){
		root = recAdd(root, x);
		return true;
	}
	else {
		return false;
	}
}

Node* AVL::IOP(Node* curr, Node* parent){

	if (curr->right == NULL){
		int swapData = parent->data;
		parent->data = curr->data;
		curr->data = swapData;

		Node* savedNode = curr->left;
		delete curr;
		return balance(savedNode);
	}
	else {
		curr->right = IOP(curr->right, parent);
		return balance(curr);
	}
}

Node* AVL::recRemove(Node* c, int x){

	if (x == c->data){

		if (c->left == NULL ){
			 Node* temp = c->right;
			 delete c;
			 return balance(temp);
		}
		else{
			c->left = IOP(c->left, c);
			return balance(c);
		}
	}

	if (x < c->data){
		c->left = recRemove(c->left, x);
		return balance(c);
	}

	if (x > c->data){
		c->right = recRemove(c->right, x);
		return balance(c);
	}
}

bool AVL::remove(int data){

	if (contains(data)){
		root = recRemove(root, data);
		return true;
	}
	else {
		return false;
	}
}

void AVL::clear(){

	while (root != NULL){
		remove(root->data);
	}
}