#include "GPAInterface.h"
#include "Student.h"

class GPA : public GPAInterface {
    
public:
    GPA(){};
    virtual ~GPA(){clear();};
    virtual map<unsigned long long int,StudentInterface*> getMap(){return student_map;};
    virtual set<StudentInterface*,Comparator> getSet(){return student_set;};
	virtual bool importStudents(string mapFileName, string setFileName);
	virtual bool importGrades(string fileName);
	virtual string querySet(string fileName);
	virtual string queryMap(string fileName);
	virtual void clear();
private:
    
    double convert_grade(string grade);
    unsigned long long int string_to_id(string str);
    bool determine_file_length(string file_name, int input_length);
    map<unsigned long long int, StudentInterface*> student_map;
    set<StudentInterface*, Comparator> student_set;
    
};