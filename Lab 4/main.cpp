#include <iostream>
#include <string>

using namespace std;

int main() {

	int menu_item;
	bool menu_display = true;

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
			case 1: cout << "ITEM 1\n" << endl; break;
			case 2: cout << "ITEM 2\n" << endl; break;
			case 3: cout << "ITEM 3\n" << endl; break;
			case 4: cout << "ITEM 4\n" << endl; break;
			case 5: cout << "ITEM 5\n" << endl; break;
			case 6: cout << "ITEM 6: GOODBYE\n" << endl; menu_display = false; break;
			default: cout << "Please enter a valid selection" << endl;

			cin.clear();
			cin.ignore(100000);
		}
	}

	return 0;
	
}