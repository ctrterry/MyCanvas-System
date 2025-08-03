#pragma once
#include <fstream>
#include "menu.h"
#include "login.h"
#include "dateTime.h"

using namespace std;

const string USERS_DATA = "users.csv";

enum LOGIN_MENU_OPTION {
	LOGIN='1',
	CREATE='2',
	RESET='3',
	EXIT='x'
};

class LoginMenu : public Menu {

public: 
	LoginMenu();
	~LoginMenu();

	bool doLogin();
	void doLogout();
    void doLoginDateTime();
	void doCreate();
	void doReset();
	void doSave();			// TODO
    
    // Get Current Date and Time
    const string currentDateTime();

	

private:
	fstream inFile;
	Login login;
	vector<Login> users;
    vector<DateTime> logoutTime;
    vector<DateTime> loginDate;
	void initUserData();
	bool authenticate();
};
