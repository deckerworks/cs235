#include "CircularDLL.h"

using namespace std;

bool CircularDLL::insertHead(string name) {
    if (circle_list.contains(name)){
        cout << "Name already in roster" << endl;
        return false;
    }
    else {
        circle_list.insert_head(name);
        //cout << "Name successfully added to roster" << endl;
        return true;
    }
};

bool CircularDLL::insertTail(string name) {
    if (circle_list.contains(name)){
        cout << "Name already in roster" << endl;
        return false;
    }
    else {
        circle_list.insert_tail(name);
        //cout << "Name successfully added to roster" << endl;
        return true;
    }
};

bool CircularDLL::insertAt(string name, int index) {
    
	if (index == 0) {
		circle_list.insert_head(name);
	}
	else {
		circle_list.insertAfter(name, circle_list.at(index - 1));
	}
	return true;
    
};

bool CircularDLL::removeHead() {
    if (circle_list.Capacity() == 0) 
        return false;
    else{
        circle_list.remove_head();
        return true;
    }
};

bool CircularDLL::removeTail() {
    if (circle_list.Capacity() == 0) 
        return false;
    else{
        circle_list.remove_tail();
        return true;
    }
    
};

bool CircularDLL::removeAt(int index) {
	if (index > circle_list.Capacity() || index < 0) {
		cout << "Index out of bounds" << endl; 
		return true;
	}
	string name = circle_list.at(index);
	circle_list.remove(name);
	cout << name << " was removed from roster" << endl;
	return true;
};

void CircularDLL::clear(){
    if (circle_list.Capacity() == 0)
        cout << "List already empty!" << endl;
    else
        circle_list.erase();
};

int CircularDLL::size() {
    return this->circle_list.Capacity();
    
};

string CircularDLL::at(int index){
    
    if (circle_list.Capacity() == 0)
        return "empty";
    else {
        if (index > -1){
            return this->circle_list.at(index);
        }
    }
};

void CircularDLL::display() {
    circle_list.display();
}

bool CircularDLL::contains(string data){
    
    if (circle_list.contains(data)){
        return true;
    }
    else{
        return false;
    }
    
}