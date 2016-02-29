#ifndef L_STACK_H_
#define L_STACK_H_

#include <iostream>

using namespace std;

template<class T> class l_stack {
public:
	l_stack() : front(NULL), back(NULL), capacity(0) {};

	void enqueue_left(T data) {
		node* insert = new node(data, front, NULL);

		if (front != NULL)
			front->prev = insert;

		front = insert;
		if (back == NULL)
			back = insert;

		capacity++;
	};

	void dequeue_left() {
		if (front != NULL) {
			if (capacity == 1){
				node* temp = front;
				front = temp->next;
				front = NULL;
				delete temp;
			}
			else{
				node* temp = front;
				front = front->next;
				delete temp;
			}
			capacity--;
		}
	};

	bool empty() {
		if (capacity == 0) return true;
		else return false;
	};

	void erase() {
		node* cur = front;
		node* temp;

		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
			temp = NULL;
		}

		front = NULL;
		back = NULL;
		capacity = 0;

	};

	bool contains(T data) {
		node* temp = front;

		//search until we find if the data is in the queue
		while (temp != NULL)
		{
			if (temp->data == data)
				return true;
			temp = temp->next;
		}

		// if the data isn't there, we return false
		return false;
	};

	void display() {
		//check to make sure there is data
		if (capacity == 0) {
			cout << "n\t***The container is empty; Nothing to display!***\n" << endl;
		}
		//print out the data
		else {
			node* temp = front;
			while (temp != NULL) {
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
	};

	int Capacity() {
		return capacity;
	}
	
	T show_left () {
		return front->data;
	}
	
	T show_right() {
		return back->data;
	}


private:
	struct node {

		T data;
		node* next;
		node* prev;

		node();
		node(T data) : data(data), next(NULL), prev(NULL) {};
		node(T data, node* next, node* prev) : data(data), next(next), prev(prev) {};
		virtual ~node() {};
	};
	
	node* front;
	node* back;
	int capacity;	

};

#endif