#pragma once
#include <fstream>
#include "announcement.h"
#include "menu.h"
#include "linkedStack.h"
#include "announcementListType.h"
#include <map>
#include "hashtable.h"
#include "myHashTable.hpp"
#include <vector>
using namespace std;

const string ANNOUNCEMENT_DATA = "announcements.dat";

enum ANNOUNCEMENT_MENU_OPTION {
	ANNOUNCEMENT_LIST = '1',
	ANNOUNCEMENT_VIEW = '2',
	ANNOUNCEMENT_ADD = '3',
	ANNOUNCEMENT_EDIT = '4',
	ANNOUNCEMENT_DELETE = '5',
	ANNOUNCEMENT_EXIT = 'x'
};

class AnnouncementMenu : public Menu {
public:

	AnnouncementMenu();
	~AnnouncementMenu();
	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();
    void getKeys();
	Announcement& getSelected() {
		return *pSelected;
	};
private:
    vector<int> _keys;
    vector<string> _titles;
	void init();
	void setSelected(Announcement& a) {
		pSelected = &a;
	};
	fstream inFile;
	Announcement* pSelected;
	AnnouncementListType* list;
    map<int,Announcement*> mapAnnouncement;
    comparied cp;
    
};
