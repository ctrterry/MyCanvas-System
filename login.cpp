#include <string>
#include <iomanip>
#include <fstream>
#include "login.h"
#include "dateTime.h"

using namespace std;

//Default constructor
Login::Login(){
	username = "";
	password = "";
}

// TODO Final Exam
void Login::setLoginTime(string s) {
	DateTime dt;
	dt.setDateTime(s);
	this->setLoginTime(dt);
}

void Login::setLogoutTime(string s) {
	DateTime dt;
	dt.setDateTime(s);
	this->setLogoutTime(dt);
}
//

//Operators compare their username
Login& Login::operator=(const  Login& other) {
	this->setUsername(other.getUsername());
	this->setPassword(other.getPassword());
	// to date time
	return *this;
}

bool Login::operator>=(const Login& otherL) const {
	return (username >= otherL.username);
}
bool Login::operator==(const Login& otherL) const {
	return (username == otherL.username);
}