#include "CircularDLL.h"

using namespace std;

bool CircularDLL::insertHead(string name);
bool CircularDLL::insertTail(string name);
bool CircularDLL::insertAt(string name, int index) ;
bool CircularDLL::removeHead();
bool CircularDLL::removeTail();
bool CircularDLL::removeAt(int index);
void CircularDLL::clear();
int CircularDLL::size();
string CircularDLL::at(int index);