#pragma once
#include <fstream>
#include "unorderedArrayListType.h"
#include "menu.h"
#include "faculty.h"

using namespace std;

enum FACULTY_MENU_OPTION {
	FACULTY_LIST = '1',
	FACULTY_VIEW = '2',
	FACULTY_ADD = '3',
	FACULTY_EDIT = '4',
	FACULTY_DELETE = '5',
	FACULTY_EXIT = 'x'
};

const string FACULTY_DATA = "/Users/terrychen/Desktop/xCodeProjectFolder/Solution/Solution/Lab6Fixed/Lab6Fixed/faculty_data.csv";

class FacultyMenu : public Menu {
public:
	FacultyMenu();
	~FacultyMenu();
	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
	
	Faculty& getSelectedFaculty() {
		return *pFaculty;
	};

	Faculty* find(Faculty& f);
private:
	void selectedFaculty(Faculty& f) {
		pFaculty = &f;
	};

	fstream inFile;
	Faculty* pFaculty;
	void init();
	UnorderedArrayListType<Faculty>* list;
};
