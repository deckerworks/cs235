#include "station.h"
#include "l_deque.h"


//Station operations

bool station::addToStation(int car) {
	
	cout << "attempting to add car --" << car << "-- to station" << endl;
	
	if (current_car == NCAR && car >= 0 && is_not_dupe(car) ) {
		current_car = car;
		return true;
		
	}
	else {
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
		return true;
	}
	else {
		return false;
	}
};

//Part 2--------------------------------------------------------------
bool station::addToStack() {
	//we will only be using the left_functions for the stacks
	//cout << "Attempting to add --" << car << "-- to stack" << endl;
	
	if (current_car == NCAR){
		cout << "NO CAR ADDED--STATION EMPTY" << endl;
		return false;
	}
	else {
		stack.enqueue_left(current_car);
		cout << "CURRENT CAR ADDED TO STACK" << endl;
		current_car = NCAR;
		return true;
	}
};


bool station::removeFromStack() {
	
	//cout << "Attempting to remove --" << car << "-- from stack" << endl;
	
	if (stack.Capacity() == 0 || current_car != NCAR){
		return false;
	}
	else {
		int car = stack.show_left();
		stack.show_left();
		current_car = car;
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
	
	
	
};


bool station::removeFromQueue() {
	
	
	
};


int station::showTopOfQueue() {
	
	
};


int station::showSizeOfQueue() {
	
	
};

//Part 4--------------------------------------------------------------

bool station::addToDequeLeft() {
	
	
};


bool station::addToDequeRight() {
	
	
};


bool station::removeFromDequeLeft() {
	
	
};


bool station::removeFromDequeRight() {
	
	
};


int station::showTopOfDequeLeft() {
	
	
};


int station::showTopOfDequeRight() {
	
	
};


int station::showSizeOfDeque() {
	
	
};

bool station::is_not_dupe(int id) {
	
	
};
