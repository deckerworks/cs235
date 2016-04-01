#include "StudentInterface.h"

class Student : public StudentInterface {
    
    public:
        
        Student(unsigned long long int id, string name, string address, string phone) : id(id), name(name), address(address), phone(phone) {
    		total_gpa = 0.0;
    		num_classes = 0.0;
	    };
	    virtual ~Student() {};
        
        unsigned long long int getID();
		virtual string getName();
		virtual string getGPA();
		virtual void addGPA(double classGrade);
		virtual string toString();
    
    private:
        unsigned long long int id;
        string name;
        string address;
        string phone;
        double total_gpa;
        double num_classes;
};