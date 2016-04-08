#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * WARNING: You may not modify any part of this document, including its name
 */

class QS : public QSInterface {
	
	public:
		QS(){
		    arr = NULL;
		    size = 0;
		    capacity = 0; 
		};
		virtual ~QS(){ clear();};
		virtual void sortAll();
		virtual int medianOfThree(int left, int right);
		virtual int partition(int left, int right, int pivotIndex);
		virtual string getArray();
		virtual int getSize();
		virtual void addToArray(int value);
		virtual bool createArray(int capacity);
		virtual void clear();
		
	private:
	    void QS_recursive(int l, int r);
	    void swap(int l, int r);
	    int* arr;
	    int size;
	    int capacity;
};



#endif /* QS_H_ */
