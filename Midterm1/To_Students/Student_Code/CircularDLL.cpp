#include "CircularDLL.h"

using namespace std;

bool CircularDLL::insertHead(string name) {
    if (circle_list.contains(name)){
        cout << "Name already in roster" << endl;
        return false;
    }
    else {
        circle_list.insert_head(name);
        cout << "Name successfully added to roster" << endl;
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
        cout << "Name successfully added to roster" << endl;
        return true;
    }
};

bool CircularDLL::insertAt(string name, int index) {
    
    
    
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
    
};

void CircularDLL::clear(){
    if (circle_list.Capacity() == 0)
        cout << "List already empty!" << endl;
    else
        circle_list.erase();
};

int CircularDLL::size() {
    return circle_list.Capacity();
    
};

string CircularDLL::at(int index){
    
    if (circle_list.Capacity() == 0)
        return "empty";
    else {
        if (index > 0){
            //int return_val = index % circle_list.Capacity();
            return circle_list.at(index);
            //return circle_list.at(index);
        }
        else if (index < 0) {
            
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