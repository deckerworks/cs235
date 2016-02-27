#ifndef STATION_H_
#define STATION_H_

#include "StationInterface.h"
#include "l_deque.h"

class station : public StationInterface
{
public:
	station();
	virtual ~station();
	//Part 1--------------------------------------------------------------
	/**
	* Let another car arrive at the station and become the current car.
	* Do not allow a new car to arrive if any of the following conditions apply:
	* 1.	There is already a current car
	* 2.	The new car's ID already exists in any structure
	* 3.	The new car's ID is negative
	*
	* @param car the ID of the car arriving at the station
	* @return true if the car successfully arrived; false otherwise
	*/
	virtual bool addToStation(int car);
	virtual int showCurrentCar();
	virtual bool removeFromStation();

	//Part 2--------------------------------------------------------------
	virtual bool addToStack();
	virtual bool removeFromStack();
	virtual int showTopOfStack();
	virtual int showSizeOfStack();

	//Part 3--------------------------------------------------------------
	virtual bool addToQueue();
	virtual bool removeFromQueue();
	virtual int showTopOfQueue();
	virtual int showSizeOfQueue();

	//Part 4--------------------------------------------------------------
	virtual bool addToDequeLeft();
	virtual bool addToDequeRight();
	virtual bool removeFromDequeLeft();
	virtual bool removeFromDequeRight();
	virtual int showTopOfDequeLeft();
	virtual int showTopOfDequeRight();
	virtual int showSizeOfDeque();


private:

	l_deque<int> stack;
	l_deque<int> queue;
	l_deque<int> deque;
	static const int NCAR = -1;
	int current_car;

	bool is_not_dupe(int id);

};

#endif