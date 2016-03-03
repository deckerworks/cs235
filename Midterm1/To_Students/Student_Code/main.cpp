#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <time.h>
#include <stdlib.h>
#include "Factory.h"
#include "CircularDLLInterface.h"

using namespace std;

//shuffle the deque randomly
void shuffle(deque<string>& names)
{
	//return if the size of the deque is too small
	if (names.size() <= 1) {
		return;
	}

	int i, index;
	string tmp;
	srand(time(NULL));
	int n = names.size();
	for (i = n - 1; i>0; i--)
	{
		index = rand() % (i + 1);
		tmp = names[i];
		names[i] = names[index];
		names[index] = tmp;
	}
}

int main() {
    
    bool menu_display = true;
    int menu_choice;
    ifstream in_file;
    string file_name;
    string name;
    int index;
    deque<string> band;
    
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
                    if (band.size() > 0)
                        band.clear();
                    while(!in_file.eof()){
                    getline(in_file, name);
                    
                    if (name != "")
                        band.push_back(name);
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
                if (band.size() == 0) {
                    cout << "Band is empty! Please insert names before display!\n" << endl;
                }
                else{
                    
                    for (int i = 0; i < band.size(); i++)
                        cout << i <<" Name: " << band[i] << endl;
                    cout << endl;
                }
                break;
                
            case 3: 
                cout << "Name to enter: ";
                cin >> name;
                
                if (band.size() == 0) {
                    band.push_front(name);
                }
                else{
                    for (int i = 0; i < band.size(); i++){
                        if (band[i] == name) {
                            cout << "NAME ALREADY IN ROSTER\n" << endl;
                            break;
                        }
                    }
                    cout << "inserting at beginning!\n" << endl;
                    band.push_front(name);
                }
                break;

            case 4: 
                cout << "Name to enter: ";
                cin >> name;
                if (band.size() == 0) {
                    band.push_back(name);
                }
                else{
                    for (int i = 0; i < band.size(); i++){
                        if (band[i] == name) {
                            cout << "NAME ALREADY IN ROSTER\n" << endl;
                            break;
                        }
                    }
                    cout << "inserting at ending!\n" << endl;
                    band.push_back(name);
                }
                break;

            case 5: 
                if (band.size() == 0) {
                    cout << "Band is empty! Insert names before removing!\n" << endl; 
                }
                else {
                    cout << "Index of name to remove: ";
                    cin >> index;
                    band.erase(band.begin() + index);
                }
                break;
            
            case 6: 
                shuffle(band);
                break;
            
            case 7: break;
            
            case 8: break;
            
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