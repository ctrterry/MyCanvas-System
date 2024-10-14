#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <sstream>
#include <vector>
#include "loginMenu.h"
#include "login.h"
#include "menu.h"
#include "utils.h"
#include "myOpenFilesExceptionHandle.hpp"
#include "loginExceptionHandling.hpp"
using namespace std;

static int ACCOUNT_INDEX = -1;
LoginMenu::LoginMenu() 
    : Menu("Login Menu") {
    addOption("1) Login");
    addOption("2) Create New Account");
    addOption("3) Reset Password");
    addOption("x) Exit Login");

	// populate all users.csv
	initUserData();
};

LoginMenu::~LoginMenu() {
	inFile.close();
}

void LoginMenu::initUserData() {
    string fileName = USERS_DATA;
    bool valid = false ;
    int attempt = 0;
    while(!valid){
        attempt++;
        if(attempt < 3){
            valid = true;
        }
        try{
            // return true or False. for openFile .
            if(openFile(inFile, fileName)){
                break;
            }
            else {
                throw myOpenFilesExceptionHandle();
            }
        }
        catch (myOpenFilesExceptionHandle & op){
            cout << "Login Data: " << op.what() << "Eg, users_data.csv " << endl;
            fileName = getUserFileInput();
        }
    }

	string  username;
	string  password;
	string  loginDateTime;
	string  logoutDateTime;

	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, loginDateTime, ',');
		getline(ss, logoutDateTime, ',');
		Login _login;
		_login.setUsername(username);
		_login.setPassword(password);
        users.push_back(_login);
        DateTime _datetime;
        _datetime.setDateTime(loginDateTime);
        loginDate.push_back(_datetime);
        _datetime.setDateTime(logoutDateTime);
        logoutTime.push_back(_datetime);
	}

	inFile.clear();
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int) users.size(); i++) {
        ACCOUNT_INDEX++;
		if (login.getUsername() == users.at(i).getUsername() &&
			login.getPassword() == users.at(i).getPassword()) {
			valid = true;
			break;
		}
	}
	return valid;
}

bool LoginMenu::doLogin() {
    cout << "***** User login *****" << endl;
    bool valid = false;
    int attempt = 3;
    while(!valid){
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        login.setUsername(username);
        login.setPassword(password);
        cout << endl;
        --attempt;
        if(attempt == 0){
            break;
        }
        try {
            if(authenticate()){
                valid = true;
                break;
            }
            else{
                throw myLoginExceptionHandling();
            }
        }
        catch(myLoginExceptionHandling &log){
            cout << log.what() << "\nTry again for " << attempt << " Times"<< endl;
        }

    }
    return valid;

}

const string LoginMenu::currentDateTime(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%m/%d/%Y %X", &tstruct);
    return buf;
}

void LoginMenu::doCreate() {
    cout << "***** Creative Account *****" << endl;
    int attempt = 2;
    do{
        cout << "\nEnter Your New Account Numbers: ";
        string acc;
        cin >> acc;
        cout << "\nEnter Your New Password Numbers: ";
        string pass1;
        cin >> pass1;
        cout << "\nAgains Your New Password Numbers: ";
        string pass2;
        cin >> pass2;
        if(pass1 == pass2){
            Login creative_login;
            creative_login.setUsername(acc);
            creative_login.setPassword(pass2);
            users.push_back(creative_login);
            // collection Currently Times
            DateTime temp;
            string currentDate = currentDateTime();
            temp.setDateTime(currentDate);
            loginDate.push_back(temp);
            break;
            
        }else {
            cout << "\nBoth Passwords are Not Match and Try Again Allowd Times "
            << attempt << endl << endl;
            --attempt;
            
        }
    }while(attempt > 0);
}


void LoginMenu::doReset() {
    // TODO: Lab 5 - change password
    cout << "***** Reset Password *****" << endl;
    cout << "Enter Your Account Name: ";
    string account;
    cin >> account;
    for(int i=0; i< users.size();i++){
        if(account == users.at(i).getUsername()){
                cout << "\nEnter Your New Password Numbers: ";
                string pass1;
                cin >> pass1;
                cout << "\nAgains Your New Password Numbers: ";
                string pass2;
                cin >> pass2;
                if(pass1 == pass2){
                    Login creative_login;
                    creative_login.setUsername(account);
                    creative_login.setPassword(pass2);
                    users.erase(users.begin()+i);
                    users.push_back(creative_login);
                    cout << "\n***** Successfully Reset Password *****" << endl;
                    break;
                }
            }
        cout << "\nAccount Not Exist !" << endl << endl;
    }
    
}

void LoginMenu::doLoginDateTime(){
    cout << "Login Date: " <<loginDate.at(ACCOUNT_INDEX).getCombiteDate() << endl;
    cout << "Login Time: " << loginDate.at(ACCOUNT_INDEX).getCombiteTime() << endl;
}

void LoginMenu::doLogout() {
    if(ACCOUNT_INDEX == -1 ){
        ACCOUNT_INDEX++;
    }
    cout << "LogOut Date: " <<  logoutTime.at(ACCOUNT_INDEX).getCombiteDate() << endl;
    cout << "Logout Time: " << logoutTime.at(ACCOUNT_INDEX).getCombiteTime() << endl;
};

/**
* Save to file
*/
void LoginMenu::doSave() {
    // conllection Currently Logout Times. 
    DateTime temp;
    string currentDate = currentDateTime();
    temp.setDateTime(currentDate);
    logoutTime.push_back(temp);
    cout << "Saving... " << USERS_DATA << endl;
    if(inFile.is_open()){
        for(int i=0; i< users.size();i++){
            inFile << users.at(i).getUsername() << ","
            << users.at(i).getPassword() << "," << loginDate.at(i).getCombiteDate() << "," << loginDate.at(i).getCombiteTime() << "," <<
            logoutTime.at(i).getCombiteDate() << "," <<
            logoutTime.at(i).getCombiteTime() <<"\n";
        }
    }
    else{
        cerr << "Failed to open file : " << USERS_DATA
            << " (errno " << errno << ")" << endl;
    }
    cout << "Save!!!" << endl << endl;
    
}
