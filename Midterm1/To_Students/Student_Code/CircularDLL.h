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
	virtual ~CircularDLL(){
		circle_list.erase();
	};
	virtual bool insertHead(string name);
	virtual bool insertTail(string name);
	virtual bool insertAt(string name, int index) ;
	virtual bool removeHead();
	virtual bool removeTail();
	virtual bool removeAt(int index);
	virtual void clear();
	virtual int size();
	virtual void display();
	virtual string at(int index);
private:
	Template_LL<string> circle_list;
	virtual bool contains(string data);
};
