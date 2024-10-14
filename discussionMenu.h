#pragma once

#include <fstream>
#include "discussion.h"
#include "menu.h"
#include "unorderedLinkedList.h"
#include "discussionListType.h"

using namespace std;

const string DISCUSSION_DATA = "/Users/terrychen/Desktop/xCodeProjectFolder/Solution/Solution/Lab6Fixed/Lab6Fixed/discussions.dat";

enum DISCUSSION_MENU_OPTION {
	DISCUSSION_LIST = '1',
	DISCUSSION_VIEW = '2',
	DISCUSSION_ADD = '3',
	DISCUSSION_EDIT = '4',
	DISCUSSION_DELETE = '5',
	DISCUSSION_EXIT = 'x'
};

class DiscussionMenu : public Menu {
	friend ostream& operator<<(ostream&, Discussion&);
	friend istream& operator>>(istream& in, Discussion& a);

public:

	DiscussionMenu();
	~DiscussionMenu();

	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
	Discussion& getSelectedDiscussion() {
		return *pDiscussion;
	};

private:
	void print(Discussion d);
	//void setStudent(Student& s, string name); Move to class Person::setFullName
	void init();
	void setDiscussion(Discussion& d) {
		pDiscussion = &d;
	};

	fstream inFile;
	Discussion* pDiscussion;
	DiscussionListType* list; // Lab 5
};
