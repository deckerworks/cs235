#ifndef STATION_H_
#define STATION_H_

#include "station.h"


//Station operations

bool station::addToStation(int car) {
	
	cout << "attempting to add car --" << car << "-- to station" << endl;
	
	if (current_car == NCAR && is_not_dupe(car) ) {
		current_car = car;
		cout << "Train successfully made it to the station!" << endl;
		return true;
		
	}
	else {
		cout << "Train Not added to station" << endl;
		return false;
	}
};


int station::showCurrentCar() {
	return current_car;
};


bool station::removeFromStation() {
	
	//cout << "removing --" << car << "-- from station" << endl;
	
	if (current_car != NCAR) {
		current_car = NCAR;
		cout << "Car successfully left the Station!" << endl;
		return true;
	}
	else {
		cout << "Station is already empty!" << endl;
		return false;
	}
};

//Part 2--------------------------------------------------------------
bool station::addToStack() {
	//we will only be using the left_functions for the stacks
	//cout << "Attempting to add --" << car << "-- to stack" << endl;
	
	if (current_car == NCAR || stack.Capacity() == 5){
		cout << "Station empty or STACK full!" << endl;
		//cout << "NO CAR ADDED--STATION EMPTY" << endl;
		return false;
	}
	else {
		stack.enqueue_left(current_car);
		//cout << "CURRENT CAR ADDED TO STACK" << endl;
		current_car = NCAR;
		return true;
	}
};


bool station::removeFromStack() {
	
	//cout << "Attempting to remove --" << car << "-- from stack" << endl;
	
	if (stack.Capacity() == 0 || current_car != NCAR){
		cout << "STACK IS EMPTY" << endl;
		return false;
	}
	else {
		current_car = stack.show_left();
		stack.dequeue_left();
		return true;
	}
	
};


int station::showTopOfStack() {

	if (stack.Capacity() == 0)
		return NCAR;
	else
		return stack.show_left();

};


int station::showSizeOfStack() {
	return stack.Capacity();	
};



//Part 3--------------------------------------------------------------
bool station::addToQueue() {
	
	if (current_car == NCAR || queue.Capacity() == 5){
		cout << "Station empty or QUEUE full!" << endl;
		return false;
	}
	else {
		queue.enqueue_right(current_car);
		current_car = NCAR;
		return true;
	}
};


bool station::removeFromQueue() {
	
	if (queue.Capacity() == 0 || current_car != NCAR){
		cout << "QUEUE IS EMPTY" << endl;
		return false;
	}
	else {
		current_car = queue.show_right();
		queue.dequeue_left();
		return true;
	}
};


int station::showTopOfQueue() {
	
	if (queue.Capacity() == 0) {
		return NCAR;
	}
	else {
		return queue.show_right();
	}
	
};


int station::showSizeOfQueue() {
	return queue.Capacity();
	
};



//Part 4--------------------------------------------------------------

bool station::addToDequeLeft() {
	
	if (current_car == NCAR || deque.Capacity() == 5){
		cout << "Station empty or DEQUE full!" << endl;
		return false;
	}
	else {
		deque.enqueue_left(current_car);
		current_car = NCAR;
		return true;
	}
};


bool station::addToDequeRight() {
	
	if (current_car == NCAR || deque.Capacity() == 5){
		cout << "Station empty or DEQUE full!" << endl;
		return false;
	}
	else {
		deque.enqueue_right(current_car);
		current_car = NCAR;
		return true;
	}
	
};


bool station::removeFromDequeLeft() {
	
	if (deque.Capacity() == 0 || current_car != NCAR){
		cout << "DEQUE IS EMPTY" << endl;
		return false;
	}
	else {
		current_car = deque.show_left();
		deque.dequeue_left();
		return true;
	}
	
};


bool station::removeFromDequeRight() {
	
	if (deque.Capacity() == 0 || current_car != NCAR){
		cout << "DEQUE IS EMPTY" << endl;
		return false;
	}
	else {
		current_car = deque.show_right();
		deque.dequeue_right();
		return true;
	}
	
};


int station::showTopOfDequeLeft() {
	
	if (deque.Capacity() == 0)
		return NCAR;
	else
		return deque.show_left();
	
};


int station::showTopOfDequeRight() {
	
	if (deque.Capacity() == 0)
		return NCAR;
	else
		return deque.show_right();
	
};


int station::showSizeOfDeque() {
	return deque.Capacity();
	
	
};



bool station::is_not_dupe(int id) {
	
	//bool unique;

	// Check all three containers
	if(stack.contains(id)){
		cout << "That is not a unique ID. ID contained in STACK" << endl;
		return !stack.contains(id);
	}

	if (queue.contains(id)) {
		cout << "That is not a unique ID. ID contained in QUEUE" << endl;
		return !queue.contains(id);
	}

	if (deque.contains(id)) {
		cout << "That is not a unique ID. ID contained in DEQUE" << endl;
		return !deque.contains(id);
	}

	return true;
};

#endif