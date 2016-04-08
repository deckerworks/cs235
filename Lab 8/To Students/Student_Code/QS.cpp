#include "QS.h"
#include <iostream>
#include <string>
#include <sstream>

void QS::sortAll(){
    QS_recursive(0, size - 1);
};

void QS::QS_recursive(int left, int right){
    
    if (left==right) return;
    else if (left + 1 == right || left + 2 == right) {
        medianOfThree(left,right);
        return;
    }
    else {
        int mid = medianOfThree(left,right);
        mid = partition(left,right,mid);
        QS_recursive(left, mid-1);
        QS_recursive(mid + 1, right);
    }
};


int QS::medianOfThree(int left, int right){
    
    int mid;
    
    if (arr == NULL || left < 0 || right > capacity - 1 || left >= right)
        mid = -1;
    else{
        mid = (left+right) / 2;
        
        while(arr[left] > arr[mid] || arr[mid] > arr[right] || arr[left] > arr[right]){
            
            if (arr[left] > arr[mid]){
                swap(left, mid);
            } 
            else if (arr[mid] > arr[right]){
                swap(mid, right);
            } 
            else if(arr[left] > arr[right]){
                swap(left, right);
            } 
        }
    }
    
    return mid;
    
};

int QS::partition(int left, int right, int pivotIndex){
    
    int up, down;
    
    if (arr == NULL || left < 0 || right > size - 1 || 
        pivotIndex < left || pivotIndex > right || left >= right) {
            down = -1;
        }
    else {
        up = left + 1;
        down = right - 1;
        
        swap (pivotIndex, left);
        
        while (up < down) {
            while (arr[up] <= arr[left] && up <= right) up++;
            while (arr[down] > arr[left] && down >= left) down--;
            if (down > up) swap(up, down);
        }
        swap (left, down);
    }
    return down;
};


string QS::getArray(){
    stringstream array;
	if(arr == NULL) {
		array << "";
	}
	else {
		for (int i = 0; i < size - 1; i++) {
			array << arr[i] << ",";
		}
		array << arr[size - 1];
	}
	return array.str();
};

int QS::getSize(){
    return size;
};

void QS::addToArray(int value){
    if (arr != NULL && size < capacity){
        arr[size] = value;
        size++;
    }
};

bool QS::createArray(int capacity){
    
    if (capacity < 0) {
		return false;
	} 
	else {
		if (arr != NULL) {
			clear();
		}
		arr = new int[capacity];
		this->capacity = capacity;
		return true;
	}
    
};

void QS::clear(){
    if (arr != NULL) {
		delete[] arr;
		arr = NULL;
		size = 0;
		capacity = 0;
	}
};


void QS::swap(int one, int two){
    int temp = arr[one];
    arr [one] = arr[two];
    arr[two] = temp;
};

