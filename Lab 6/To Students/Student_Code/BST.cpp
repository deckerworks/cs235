#include "BST.h"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	clear();
}

Node* BST::getRootNode() {
	return root;
}

bool BST::add(int data) {
	bool added;

	// If the tree is empty, add a new root
	if ( root == NULL ) {
		root = new Node(data);
		added = true;
	}
	// If the value is unique, add it
	else if ( !find(data, root) ) {
		add_recursive(data, root);
		added = true;
	}
	// Don't add duplicates
	else {
		added = false;
	}

	return added;
}

bool BST::remove(int data) {
	bool removed;

	// If the value exists, remove it
	if ( find(data, root) ) {
		removed = remove_recursive(data, root);
	}
	else {
		removed = false; // can't remove it if it doesn't exist in the tree
	}

	return removed;
}

void BST::clear() {
	// Empty the tree unless it is already empty
	if ( root != NULL )
		clear_recursive(root);
}

void BST::clear_recursive(Node*& node) {
	// Move left if you can
	if ( node->left_child != NULL )
		clear_recursive(node->left_child);

	// Move right if you can
	if ( node->right_child != NULL )
		clear_recursive(node->right_child);

	// Once all the children of the node are deleted from above calls, delete the node
	delete node;
	node = NULL;
}

bool BST::add_recursive(int data, Node*& current) {
	// Once you get to the bottom of the tree, add the node
	if (current == NULL) {
		current = new Node(data);
		return true;
	}
	// If you aren't at the bottom of the tree, keep moving out.
	else {
		if (data > current->data) {
			return add_recursive(data, current->right_child);
		}
		else {
			return add_recursive(data, current->left_child);
		}
	}
}

bool BST::remove_recursive(int data, Node*& current) {
	bool removed;
	// Once you've arrived to the correct node, delete the node
	if ( data == current->data ) {
		// No children
		if ( current->right_child == NULL && current->left_child == NULL ) {
			delete current;
			current = NULL;
			return true;
		}
		// One child
		else if ( (current->right_child == NULL && current->left_child != NULL)
			   || (current->left_child == NULL && current->right_child != NULL)) {
			Node * temp = current;

			// Move up the existing child node
			if (current->left_child == NULL)
				current = current->right_child;
			else
				current = current->left_child;

			delete temp;
			temp = NULL;
			return true;
		}
		// Two children
		else if ( current->right_child != NULL && current->left_child != NULL ) {
			// Find the inorder predecessor and put it where the deleted node is.
				// Deleting, swapping, etc. happens within the inorder_predecessor function
			return inorder_predecessor(current, current->left_child);
		}
	}
	else { // Recurse
		if (data > current->data) {
			return remove_recursive(data, current->right_child);
		}
		else {
			return remove_recursive(data, current->left_child);
		}
	}
}

bool BST::inorder_predecessor(Node*& n1, Node*& n2) {
	// If right == NULL, you have found the inorder predecessor
	if ( n2->right_child == NULL ) {
		n1->data = n2->data;
		Node* temp = n2;
		n2 = n2->left_child;
		delete temp;
		temp = NULL;
		return true;
	} else {
		inorder_predecessor(n1, n2->right_child);
	}
}

bool BST::find(int value, Node* n) {
	bool found;

	if (n == NULL) {
		found = false;
	}
	else if ( n->data == value ) {
		found = true;
	}
	else {
		if (value > n->data) {
			found = find(value, n->right_child);
		}
		else {
			found = find(value, n->left_child);
		}
	}

	return found;
}