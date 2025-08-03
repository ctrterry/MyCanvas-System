#pragma once
#include <fstream>
#include <map>
#include "menu.h"
#include "student.h"
#include "linkedQueue.h"
#include <iomanip>

using namespace std;

enum STUDENT_MENU_OPTION { STUDENT_LIST = '1', STUDENT_VIEW = '2', STUDENT_ADD = '3', STUDENT_EDIT = '4', STUDENT_DELETE = '5', STUDENT_EXIT = 'x' };

const string STUDENT_DATA = "student_data.csv";

class StudentMenu : public Menu { 
public:
	StudentMenu();
	~StudentMenu();
	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
    
    //Overloaded operators
    bool operator>=(const StudentMenu&) const;
    bool operator<=(const StudentMenu&) const;
    bool operator<(const StudentMenu&) const;
    bool operator>(const StudentMenu&) const;
    bool operator==(const StudentMenu&) const;
    bool operator!=(const StudentMenu&) const;
    
    // Print Personal Header
    void printStudentHead() const{
        cout << left
            << setw(5) << "ID"
            << setw(15)    << "First Name"
            << setw(15)    << "Last Name"
            << setw(25)    << "Address"
            << setw(15)    << "City"
            << setw(5)    << "State"
            << setw(15)    << "Phone Number"
            << setw(20)    << "Email"
            << endl;
    }
    
    
private:
	fstream inFile;
	void init();
	LinkedQueueType<Student>* list;
	map<string, Student*> mapStudent;
};
