#ifndef L_DEQUE_H_
#define L_DEQUE_H_

#include <iostream>

using namespace std;

template<class T> class l_deque {
public:
	l_deque() : head(NULL), tail(NULL), capacity(0) {};

	void enqueue_right(T data) {
		node* insert = new node(data, NULL, tail);

		if (tail != NULL)
			tail->next = insert;

		tail = insert;
		if (head == NULL)
			head = insert;

		capacity++;
	};


	void enqueue_left(T data) {
		node* insert = new node(data, head, NULL);

		if (head != NULL)
			head->prev = insert;

		head = insert;
		if (tail == NULL)
			tail = insert;

		capacity++;
	};

	void dequeue_right() {
		if (tail != NULL) {
			if (capacity == 1){
				node* temp = tail;
				tail = temp->prev;
				tail = NULL;
				delete temp;
			}
			else{
				node* temp = tail;
				tail = tail->prev;
				delete temp;
			}
			capacity--;
		}
	};


	void dequeue_left() {
		if (head != NULL) {
			if (capacity == 1){
				node* temp = head;
				head = temp->next;
				head = NULL;
				delete temp;
			}
			else{
				node* temp = head;
				head = head->next;
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
		node* cur = head;
		node* temp;

		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
			temp = NULL;
		}

		head = NULL;
		tail = NULL;
		capacity = 0;

	};

	bool contains(T data) {
		node* temp = head;

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
			node* temp = head;
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
		return head->data;
	}
	
	T show_right() {
		return tail->data;
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
	
	node* head;
	node* tail;
	int capacity;	

};

#endif