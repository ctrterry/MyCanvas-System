#pragma once
#include <fstream>
#include <vector>
#include "course.h"
#include "courseListType.h"
#include "menu.h"
#include "facultyMenu.h"

using namespace std;

const string COURSE_DATA = "/Users/terrychen/Desktop/xCodeProjectFolder/Solution/Solution/Lab6Fixed/Lab6Fixed/course_data.csv";

enum COURSE_MENU_OPTION {
	COURSE_LIST='1',
    COURSE_LIST_BY = '2',
	COURSE_VIEW='3',
	COURSE_ADD='4',
	COURSE_EDIT='5',
	COURSE_DELETE='6',
	COURSE_EXIT='x' 
};

class CourseMenu : public Menu {
public:
	CourseMenu();
	~CourseMenu();

	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();
	void doFacultyMenu();	// Lab 5
	void doSortedList();	// lab5

	Course& getSelectedCourse() {
		return *pCourse;
	};

	bool isSelectedCourse() const {
		return pCourse != nullptr;
	};
    
private:
	void init();
	void selectedCourse(Course& c) {
		pCourse = &c;
	};

	fstream inFile;
	FacultyMenu facultyMenu;	// Lab 5
	Course* pCourse;	
	CourseListType *list;		// Lab 5
};
