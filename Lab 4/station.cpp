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


bool station::removeFromStation(int car) {
	
	cout << "removing --" << car << "-- from station" << endl;
	
};

//Part 2--------------------------------------------------------------
bool station::addToStack(
	//we will only be using the left_functions for the stacks
	
	) {
	
	
	
	
	return false;
};
bool station::removeFromStack() {};
int station::showTopOfStack() {};
int station::showSizeOfStack() {};

//Part 3--------------------------------------------------------------
bool station::addToQueue() {};
bool station::removeFromQueue() {};
int station::showTopOfQueue() {};
int station::showSizeOfQueue() {};

//Part 4--------------------------------------------------------------
bool station::addToDequeLeft() {};
bool station::addToDequeRight() {};
bool station::removeFromDequeLeft() {};
bool station::removeFromDequeRight() {};
int station::showTopOfDequeLeft() {};
int station::showTopOfDequeRight() {};
int station::showSizeOfDeque() {};

bool station::is_not_dupe(int id) {
	
	
};
