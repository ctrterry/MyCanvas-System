#include "dateTime.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "discussion.h"

using namespace std;

Discussion::Discussion() {
	// TODO...
}

string Discussion::getText() const {
	return text;
}

string Discussion::getName() const {
	return student.getFirstName()
		+ (student.getMiddleName().empty() ? (" " + student.getMiddleName()) : "")
		+ " " + student.getLastName();
}

void Discussion::print() const {
	cout << getName() << endl;
	cout << getDateTime().toString() << endl;
	cout << getText() << endl;
	cout << "--------------------------------------------------" << endl;
}

Discussion& Discussion::operator=(const Discussion& other) {
	student.copy(other.getStudent());
	postDate.copy(other.getDateTime());
	text = other.getText();
	return *this;
}

bool Discussion::operator==(const Discussion& otherF) const {
	return getName() == otherF.getName();
}
bool Discussion::operator!=(const Discussion& otherF) const {
	return !(*this == otherF);
}

bool Discussion::operator>(const Discussion& otherF) const {
	return getName() > otherF.getName();
}
bool Discussion::operator<(const Discussion& otherF) const {
	return !(*this > otherF || *this == otherF);
}
bool Discussion::operator>=(const Discussion& otherF) const {
	return !(*this < otherF);
}
bool Discussion::operator<=(const Discussion& otherF) const {
	return !(*this > otherF);
}



ostream& operator<<(ostream& osObject, Discussion& a) {
	osObject << a.getName() << endl;
	osObject << a.getDateTime().toString() << endl;
	osObject << a.getText() << endl << endl;
	osObject << setfill('-') << setw(50) << "\n";
	osObject << endl;
	return osObject;
}

istream& operator>>(istream& in, Discussion& a) {
	// TODO
	// cin >> p;
    in >> a.text;
	return in;
}
