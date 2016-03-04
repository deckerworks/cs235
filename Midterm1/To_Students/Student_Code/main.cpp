#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Factory.h"
#include "CircularDLLInterface.h"
#include "CircularDLL.h"

using namespace std;



void shuffle(vector<string>& r_names) {
	//return if the size of the vector is too small
	if (r_names.size() <= 1) {
		return;
	}

	int i, index;
	string tmp;
	srand(time(NULL));
	int n = r_names.size();
	for (i = n - 1; i>0; i--)
	{
		index = rand() % (i + 1);
		tmp = r_names[i];
		r_names[i] = r_names[index];
		r_names[index] = tmp;
	}
}


void calc_Safe_Index(CircularDLL* roster, int n, int c) {

	int s = 1;
	int index = 0;
	if (c < 0) {
		c = abs(c);
	}
	while (roster->size() > s)
	{	
		index += c - 1;
		if (index >= roster->size()) index %= roster->size();
		//cout << roster->at(index) << ", ";
		roster->removeAt(index);
	}
	cout << "\n" << endl;
	cout << roster->at(0);
	cout << "\n" << endl;
}

int main() {
    
    bool menu_display = true;
    bool indexcheck = true;
    int menu_choice;
	int roster_size;
    ifstream in_file;
    string file_name;
    string name, safe_name;
    int index;
    int num_people;
    CircularDLLInterface* band = Factory::getStudentList();
	CircularDLL* temp_band = new CircularDLL();
	vector<string> shuffled;
    
    while(menu_display) {
        
        cout << "1. Import a file containing names to add to Josephus' band" << endl;
        cout << "2. Display the band roster with indices" << endl;
        cout << "3. Prepend a name manually" << endl;
        cout << "4. Append a name manually" << endl;
        cout << "5. Remove a name by index" << endl;
        cout << "6. Randomly shuffle the roster" << endl;
        cout << "7. Calculate the safe index" << endl;
        cout << "8. Dispatch the band (Simulate the Josephus Problem on the current roster)" << endl;
        cout << "9. Quit\n" << endl;
        
        cout << "User Selection: ";
        std::cin >> menu_choice;
        cout << endl;
        
        switch (menu_choice){
            case 1:
                cout << "File name (including extension): ";
                std::cin >> file_name;
                in_file.open(file_name);
                if (in_file.is_open()) {
					//if the roster isn't empty, clear it and then insert names
                    if (band->size() > 0)
                        band->clear();
                    while(!in_file.eof()){
						getline(in_file, name);
                    
						if (name != ""){
							band->insertTail(name);
							cout << name << " successfully added to roster" << endl;
						}
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
				//display each member in the band

				if (band->size() == 0) {
					cout << "Roster is empty!" << endl;
					break;
				}
				for (int i = 0; i < band->size(); i++) {
					cout << "[" <<i << "] - " << band->at(i) << endl;
				}
				cout << endl;
                break;
                
            case 3: 
                cout << "Name to enter: ";
				std::cin >> name;
                band->insertHead(name);
                break;

            case 4: 
                cout << "Name to enter: ";
				std::cin >> name;
                band->insertTail(name);
                break;

            case 5: 
                if (band->size() == 0) {
                    cout << "Band is empty! Insert names before removing!\n" << endl; 
                }
                else {
                    cout << "Index of name to remove: ";
					std::cin >> index;
					band->removeAt(index);
                }
                break;
            
            case 6:
				if (band->size() == 0) cout << "Roster is empty!\n\n"; break;

                cout << "****Shuffling!****\n" << endl;

				for (int i = 0; i < band->size(); i++) {
					shuffled.push_back(band->at(i));
				}
				band->clear();
				shuffle(shuffled);

				for (int i = 0; i < shuffled.size(); i++) {
					band->insertTail(shuffled[i]);
				}
				shuffled.clear();
                break;
            
            case 7: 
                cout << "Number of people in circle: ";
				std::cin >> num_people;
                
                while(indexcheck){
                    cout << "Counting number: ";
					std::cin >> index;
                    
                    if (index == 0) {
                        cout << "Index must be larger than 0" << endl;
                    }
                    else if (abs(index) > num_people){
                       cout << "Index must be less than the number of people" << endl;
                    }
                    else if (abs(index) < num_people){
						indexcheck == false;
						for (int i = 0; i < num_people; i++) {
							name = "temp" + to_string(i);
							temp_band->insertTail(name);
						}

						calc_Safe_Index(temp_band, num_people, index);
						//safe_name = calc_Safe_Index(temp_band, num_people, index);
						cout << safe_name << endl;
						temp_band->clear();
                        break;
                    }
                }
                break;
            
            case 8:
				while (indexcheck) {
					cout << "Counting number: ";
					std::cin >> index;

					if (index == 0) {
						cout << "Index must be larger than 0" << endl;
					}
					else if (abs(index) > band->size()) {
						cout << "Index must be less than the number of people" << endl;
					}
					else if (abs(index) < band->size()) {
						indexcheck == false;

						if (index < 0) {
							temp_band->insertHead(band->at(0));
							for (int i = band->size()-1; i > 0; i--) {
								temp_band->insertTail(band->at(i));
							}
						}

						else {
							for (int i = 0; i < band->size(); i++) {
								temp_band->insertTail(band->at(i));
							}
						}

						calc_Safe_Index(temp_band, band->size(), index);
						//safe_name = calc_Safe_Index(temp_band, num_people, index);
						//cout << safe_name << endl;
						temp_band->clear();
						break;
					}
				}



                
                break;
            
            case 9: cout << "BYE FELICIA\n" << endl; menu_display = false; break;
            
            default: cout << "Please enter a valid selection!\n\n" << endl;
            
            //cin.ignore(10000, '\n');
            //cin.clear();
        }
        
		std::cin.clear();
		std::cin.ignore(100000, '\n');
        
        
    }
    
    
    return 0;
}