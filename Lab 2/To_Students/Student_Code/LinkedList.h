#pragma once
#include <string>
#include <stdexcept>
#include "LinkedListInterface.h"

template<class T> class LinkedList : public LinkedListInterface<T>
{
public:
    LinkedList() : head(NULL), length(0) {};

    virtual ~LinkedList(){clear();};
    
    virtual void insertHead(T value){
        //check if there is content in the list; if no content, create node and exit
        if (empty_list(value)) return;

        bool dup = check_dup(value);
        //check if there are unique values in the list
        //if not, add a new node to point to the head
        if (dup) {
            head = new Node(value, head);
            length++;
        };
    };

    virtual void insertTail(T value){

        if (empty_list(value)) return;
        bool dup = check_dup(value);
        if (dup) {
            Node* temp = head;
            Node* insert = new Node(value);
            //advance to end of list
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = insert;
            temp = NULL;
            insert = NULL;
            length++;
        }

    };

    virtual void insertAfter(T value, T insertionNode){

    	bool dup = check_dup(value);
    	bool is_there = !check_dup(insertionNode);
        if (dup && is_there){
            Node* temp = head;
            //advance to insertionNode
            while (temp->data != insertionNode){
                temp=temp->next;
            }
            Node* insert = new Node(value, temp->next);
            temp->next = insert;
            temp = NULL;
            insert = NULL;
            length++;
        }
    };
    
    /*
        remove
        The node with the given value should be removed from the list.
        The list may or may not include a node with the given value.
     */
    virtual void remove(T value){

        if (!check_dup(value)){
            Node* temp = head;

            if (value == temp->data){
                head = temp->next;
                delete temp;
            }
            else{
                //advance to node before node to delete
            while(temp->next != NULL && temp->next->data != value){
                temp = temp->next;
            }

            Node* curr = temp->next;
                if (curr == NULL)
                    temp->next = NULL;
                else
                    temp->next = curr->next;
                delete curr;
                temp = NULL;
                curr = NULL;
            }
            length--;
        }
    };

    virtual void clear(){

        if (head == NULL) return;
        Node* temp = head;
        Node* curr;
        while (temp->next != NULL)
        {
            curr = temp;
            temp = temp->next;
            delete curr;
        }
        delete temp;
        temp = NULL;
        curr = NULL;
        head = NULL;
        length = 0;

    };

    virtual T at(int index){

        // Verify that the index is legal.
        if (index < 0) {
            throw out_of_range ("Index must not be negative");
        }
        else if(index >= length) {
            throw out_of_range ("Index is out of range");
        }
        else if (head == NULL) {
            throw out_of_range ("Index must exist! (empty list)");
        }
        else {
            Node* temp = head;
			for(int i = 0; i < index; i++){
				temp = temp->next;
			}
			return temp->data;
        }
    };

    virtual int size(){
        return this->length;
    };

private:
    struct Node
    {
        T data;
        Node* next;

        Node();
        Node(T data) : data(data) { this->next = NULL; };
        Node(T data, Node* next) : data(data), next(next) {};

        virtual ~Node() {};
    };

    //private member variables
    Node* head;
    int length;

    //check for duplicates in list
    bool check_dup(T value){
        Node* temp = head;
        while (temp != NULL){
            if (temp->data == value){
                return false;
            }
            temp = temp->next;
        }
        temp = NULL;
        return true;
    };

    //return true if there is content in the list
    bool empty_list(T value){
        if (head == NULL) {
			head = new Node(value);
			length++;
			return true;
		} else {
			return false;
		}

    };

};