#include "Student.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

unsigned long long int Student::getID() {
	return id;
}

string Student::getName(){
    return name;
};

string Student::getGPA(){
    stringstream ss;
    double true_gpa;
    
    if (num_classes == 0.0)
        true_gpa = 0.0;
    else
        true_gpa = total_gpa / num_classes;
    
    ss << fixed << setprecision(2) << true_gpa;
    return ss.str();
};

void Student::addGPA(double classGrade){
    total_gpa += classGrade;
    num_classes += 1;
};

string Student::toString(){
    stringstream student;
    student << this->id << "\n"
            << this->name << "\n"
            << this->address << "\n"
            << this->phone << "\n"
            << this->getGPA();
            
    return student.str();
};