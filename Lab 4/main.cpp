//#pragma once
#include <iostream>
#include <string>
#include "station.h"

using namespace std;

int main() {

	int menu_item;
	bool menu_display = true;
	string twoend;
	
	station* train_station = new station();

	while (menu_display) {

		cout << "\n--------------------------------------------------------------------------------" << endl;
		cout << "\t\t\tPlease select an operation" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << " 1: Add a car to the station" << endl;
		cout << " 2: Remove a car from the station" << endl;
		cout << " 3: Add a car from the station to a storage facility" << endl;
		cout << " 4: Remove a car from a storage facility and add it to the station" << endl;
		cout << " 5: Display the cars currently accessible in the station and storage facilities" << endl;
		cout << " 6: Quit" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << endl;

		cout << "User Selection: ";
		cin >> menu_item;

		switch (menu_item) {
			case 1: 
				int train_id;
				
				cout << "Please enter a train ID Greater than 0: ";
				cin >> train_id;
				if(!cin.fail() && train_id > 0) {
					train_station->addToStation(train_id);
				}
				else {
					cout << "INVALID ID" << endl;
				}
				cin.ignore(100000, '\n');
				cin.clear();
				
				break;
			case 2:
				train_station->removeFromStation();
				break;
			case 3: 
				int storage;
				cout << "What storage facility do you want to store the train in?" << endl;
				cout << "1: Stack" << endl;
				cout << "2: Deque" << endl;
				cout << "3: Queue" << endl;
				
				cin >> storage;
				
				if(!cin.fail() && storage > 0) {
					switch(storage){
						
						case 1: 
							train_station->addToStack(); 
							break;
						case 2: 
							
							cout << "Which end of the Deque? L/R";
							cin >> twoend;
							if (twoend == "L")
								train_station->addToDequeLeft();
							else if (twoend == "R")
								train_station->addToDequeRight();
							else
								cout << "invalid position" << endl;
							break;
						case 3: 
							train_station->addToQueue(); 
							break;
						default: 
							cout << "invalid selection!" << endl;
					}
					cin.ignore(100000, '\n');
					cin.clear();
				}
				else {
					cout << "INVALID ID" << endl;
				}
				cin.ignore(100000, '\n');
				cin.clear();
				
				break;
			case 4: cout << "ITEM 4\n" << endl; break;
			case 5:
				cout << "Accessable cars: " << endl;
				if (train_station->showSizeOfStack() == 0)
					cout << "Stack: empty" << endl;
				else
					cout << "Stack: " << train_station->showTopOfStack() << endl;
				
				if (train_station->showSizeOfDeque() == 0) 
					cout << "Deque: empty, empty" << endl;
				else
					cout << "Deque: " << train_station->showTopOfDequeLeft() << ", " << train_station->showTopOfDequeRight() << endl;
				
				if (train_station->showSizeOfQueue() == 0)
					cout << "Queue: empty" << endl;
				else
					cout << "Queue: " << train_station->showTopOfQueue() << endl;
					
				if (train_station->showCurrentCar() == -1)
					cout << "Station: empty" << endl;
				else
					cout << "Station: " << train_station->showCurrentCar() << endl;
				
				
				break;
			case 6: 
				cout << "\nChoo choo ciao!\n" << endl; 
				cout << "    ~~~ ____                           " << endl;
				cout << " __||___|  |  ______   ______   ______ " << endl;
  				cout << "(        | |      | |      | |      |" << endl;
  				cout << "/-()---() ~ ()--() ~ ()--() ~ ()--()" << endl;
  				cout << "-------------------------------------------" << endl;
				
				menu_display = false;
				break;
			default: cout << "Please enter a valid selection" << endl;

			cin.clear();
			cin.ignore(100000);
		}
	}

	return 0;
	
}