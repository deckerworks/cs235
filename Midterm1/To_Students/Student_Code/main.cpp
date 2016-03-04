#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "Factory.h"
#include "CircularDLLInterface.h"

using namespace std;

//shuffle the deque randomly
/*
void shuffle(CircularDLLInterface* names)
{
	//return if the size of the deque is too small
	if (names->size() <= 1) {
		return;
	}

	int i, index;
	string tmp;
	srand(time(NULL));
	int n = names->size();
	for (i = n - 1; i>0; i--)
	{
		index = rand() % (i + 1);
		tmp = names[i];
		names[i] = names[index];
		names[index] = tmp;
	}
}
*/
void calc_Safe_Index() {
    cout << "Two numbers: ";
    int number;
    int second_number;
    
    cin >> number >> second_number;
    cout << number % second_number;
    
    
}

int main() {
    
    bool menu_display = true;
    bool indexcheck = true;
    int menu_choice;
    ifstream in_file;
    string file_name;
    string name;
    int index;
    int num_people;
    CircularDLLInterface* band = Factory::getStudentList();	
    
    while(menu_display) {
        
        cout << "1. Import a file containing names to add to Josephus’ band" << endl;
        cout << "2. Display the band roster with indices" << endl;
        cout << "3. Prepend a name manually" << endl;
        cout << "4. Append a name manually" << endl;
        cout << "5. Remove a name by index" << endl;
        cout << "6. Randomly shuffle the roster" << endl;
        cout << "7. Calculate the safe index" << endl;
        cout << "8. Dispatch the band (Simulate the Josephus Problem on the current roster)" << endl;
        cout << "9. Quit\n" << endl;
        
        cout << "User Selection: ";
        cin >> menu_choice;
        cout << endl;
        
        switch (menu_choice){
            case 1:
                cout << "File name (including extension): ";
                cin >> file_name;
                in_file.open(file_name.c_str());
                if (in_file.is_open()) {
                    if (band->size() > 0)
                        band->clear();
                    while(!in_file.eof()){
                    getline(in_file, name);
                    
                    if (name != "")
                        band->insertTail(name);
                    else
                        cout << "EMPTY LINE" << endl;
                    }
                    in_file.close();
                    
                }
                else {
                    cout << "File failed to open\n" << endl;
                }
                cout << endl;
                break;
                
            case 2: 
                cout << "DISPLAY!" << endl;
                //band->display();
                /*
                if (band.size() == 0) {
                    cout << "Band is empty! Please insert names before display!\n" << endl;
                }
                else{
                    
                    for (int i = 0; i < band.size(); i++)
                        cout << "[" << i <<"] - " << band[i] << endl;
                    cout << endl;
                }
                */
                break;
                
            case 3: 
                cout << "Name to enter: ";
                cin >> name;
                band->insertHead(name);
                break;

            case 4: 
                cout << "Name to enter: ";
                cin >> name;
                band->insertTail(name);
                break;

            case 5: 
                if (band->size() == 0) {
                    cout << "Band is empty! Insert names before removing!\n" << endl; 
                }
                else {
                    cout << "Index of name to remove: ";
                    cin >> index;
                    //band.erase(band.begin() + index);
                }
                break;
            
            case 6: 
                //shuffle(band);
                cout << "Shuffling!" << endl;
                break;
            
            case 7: 
                cout << "Number of people in circle: ";
                cin >> num_people;
                
                while(indexcheck){
                    cout << "Counting number: ";
                    cin >> index;
                    
                    if (index == 0) {
                        cout << "Index must be larger than 0" << endl;
                    }
                    else if (abs(index) > num_people){
                       cout << "Index must be less than the number of people" << endl;
                    }
                    else if (abs(index) < num_people){
                        break;
                    }
                }
                
                cout << "Number of people in circle: " << num_people << "\nCounting number: " << index << endl;
                
                cout << "now calculating safe index...\n\n" << endl;
                
                calc_Safe_Index();
                
                
                
                break;
            
            case 8: 
                cout << "Counting number: ";
                cin >> index;
                
                break;
            
            case 9: cout << "BYE FELICIA\n" << endl; menu_display = false; break;
            
            default: cout << "Please enter a valid selection!\n\n" << endl;
            
            //cin.ignore(10000, '\n');
            //cin.clear();
        }
        
        cin.clear();
		cin.ignore(100000, '\n');
        
        
    }
    
    
    return 0;
}