#pragma once
#include <fstream>
#include "assignment.h"
#include "unorderedArrayListType.h"
#include "menu.h"

using namespace std;

const string ASSIGNMENT_DATA = "assignment_data.csv";

enum ASSIGNMENT_MENU_OPTION {
	LIST_ALL = '1',	
	LIST_PENDING = '2',
	LIST_COMPLETED = '3',
	VIEW = '4',
	ADD = '5',
	EDIT = '6',
	DELETE = '7',
	ASSIGNMENT_EXIT = 'x'
};

class AssignmentMenu : public Menu {
public:
	AssignmentMenu();
	~AssignmentMenu();

	void doList();
	void doListPending();
	void doListCompleted();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
	Assignment& getSelectedAssignment() {
		return *pAssignment;
	};

private:
	void init();
	void setAssignment(Assignment& a) {
		pAssignment = &a;
	};

	fstream inFile;
	Assignment* pAssignment;
	UnorderedArrayListType<Assignment*>* list;
};
