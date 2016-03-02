#include <iostream>
#include <string>
#include "Factory.h"
#include "CircularDLLInterface.h"

using namespace std;

int main() {
    
    bool menu_display = true;
    int menu_choice;
    
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
        
        switch (menu_choice){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: cout << "BYE" << endl; menu_display = false; break;
        }
        
        
        
    }
    
    
    return 0;
}