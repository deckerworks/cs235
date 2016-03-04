#pragma once
#include "CircularDLLInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Template_LL.h"


using namespace std;

class CircularDLL : public CircularDLLInterface {
public:
	CircularDLL(){};
	~CircularDLL(){
		circle_list.erase();
	};
	bool insertHead(string name);
	bool insertTail(string name);
	bool insertAt(string name, int index) ;
	bool removeHead();
	bool removeTail();
	bool removeAt(int index);
	void clear();
	int size();
	void display();
	string at(int index);
private:
	Template_LL<string> circle_list;
	bool contains(string data);
};
