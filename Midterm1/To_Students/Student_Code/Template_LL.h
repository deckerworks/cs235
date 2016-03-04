#ifndef Template_LL_H_
#define Template_LL_H_
#include <iostream>

using namespace std;

template<class T> class Template_LL {
public:
	Template_LL() : head(NULL), tail(NULL), capacity(0) {};

	void insert_tail(T data) {
		node* insert = new node(data, NULL, tail);

		if (tail != NULL)
			tail->next = insert;

		tail = insert;
		if (head == NULL)
			head = insert;

		capacity++;
	};


	void insert_head(T data) {
		node* insert = new node(data, head, NULL);

		if (head != NULL)
			head->prev = insert;

		head = insert;
		if (tail == NULL)
			tail = insert;

		capacity++;
	};

	void remove_tail() {
		if (tail != NULL) {
			if (capacity == 1){
				node* temp = tail;
				tail = temp->prev;
				tail = NULL;
				head = NULL;
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


	void remove_head() {
		if (head != NULL) {
			if (capacity == 1){
				node* temp = head;
				head = temp->next;
				head = NULL;
				tail = NULL;
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
	
	void insertAfter(T value, T insertionnode){

    	bool dup = contains(value);
    	bool is_there = !contains(insertionnode);
        if (dup && is_there){
            node* temp = head;
            //advance to insertionnode
            while (temp->data != insertionnode){
                temp=temp->next;
            }
            node* insert = new node(value, temp->next);
            temp->next = insert;
            temp = NULL;
            insert = NULL;
            capacity++;
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

	void remove(T data){

        if (!contains(data)){
            node* temp = head;

            if (data == temp->data){
                head = temp->next;
                delete temp;
            }
            else{
                //advance to node before node to delete
            while(temp->next != NULL && temp->next->data != data){
                temp = temp->next;
            }

            node* curr = temp->next;
                if (curr == NULL)
                    temp->next = NULL;
                else
                    temp->next = curr->next;
                delete curr;
                temp = NULL;
                curr = NULL;
            }
            capacity--;
        }
    };
    
    T at(int index){

        // Verify that the index is legal.
        if (index < 0) {
            cout << "Index must not be negative" << endl;
        }
        else if(index >= capacity) {
            cout << "Index is out of range" << endl;
        }
        else if (head == NULL) {
            cout << "Index must exist! (empty list)" << endl;
        }
        else {
            node* temp = head;
			for(int i = 0; i < index; i++){
				temp = temp->next;
			}
			return temp->data;
        }
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
    
    
    /*
	T show_head () {
		return head->data;
	}
	
	T show_tail() {
		return tail->data;
	}
	*/

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