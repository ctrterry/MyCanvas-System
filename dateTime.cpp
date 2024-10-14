#include "dateTime.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Constructor
DateType::DateType(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void DateType::copy(const DateType& otherObject) {	
	month = otherObject.month;
	day = otherObject.day;
	year = otherObject.year;
}

//Set the date by passing in a string in month_day_year, _ to represent any FORMAT_SEPARATOR
void DateType::setDate(string dateString) {
	int pos = dateString.length() > 10 ? dateString.find(" ") : 10;
	string sdate = dateString.substr(0, pos);
	pos = sdate.find(FORMAT_SEPARATOR);
    
  //  cout << "Date String and first end" << sdate.substr(0, pos) << endl;
	month = stoi(sdate.substr(0, pos));
  //  cout << "month" << month << endl;
    
	sdate = sdate.substr(pos + 1); //skip past the first delimiter

	pos = sdate.find(FORMAT_SEPARATOR);
	day = stoi(sdate.substr(0, pos));
	sdate = sdate.substr(pos + 1);

	year = stoi(sdate); //year is all remaining in the string

}

DateType& DateType::getDate() {
	return *this;
}

//Date format - mm/dd/yyyy
string DateType::toString() const {	
	return !isEmpty() ?
		to_string(month) + FORMAT_SEPARATOR + to_string(day) + FORMAT_SEPARATOR + to_string(year) : "";
}

bool DateType::operator>(const DateType& otherD) const {
	return (year > otherD.year) || (year == otherD.year && month > otherD.month)
		|| (year == otherD.year && month == otherD.month && day > otherD.day);
}
bool DateType::operator<(const DateType& otherD) const {
	//if either this > other or this = other, then this can't be < other
	return !(*this > otherD || *this == otherD);
}
bool DateType::operator>=(const DateType& otherD) const {
	//if this !< than other, then this must be > or =
	return !(*this < otherD);
}
bool DateType::operator<=(const DateType& otherD) const {
	return !(*this > otherD);
}
bool DateType::operator==(const DateType& otherD) const {
	return (year == otherD.year && month == otherD.month && day == otherD.day);
}
bool DateType::operator!=(const DateType& otherD) const {
	return !(*this == otherD);
}

/*******************************************************************/
//Constructor - also calls DateType's parameterized constructor
DateTime::DateTime(int h, int mi, int s, int mo, int d, int y) :DateType(mo, d, y) {
	hr = h;
	min = mi;
	sec = s;
}

void DateTime::copy(const DateTime& otherObject) {
	hr = otherObject.hr;
	min = otherObject.min;
	sec = otherObject.sec;

	DateType::copy(otherObject);
}

//Sets the time by passing in a string in hr:min:sec format
void DateTime::setDateTime(string dateTime) {
	string sdate, stime;
	if (dateTime.length() > 10) {
		int pos = dateTime.find(" ");
		sdate = dateTime.substr(0, pos);
		stime = dateTime.substr(pos + 1);
		this->setDate(sdate);
	}
	else {
		stime = dateTime;
	}
	hr = stoi(stime.substr(0, 2));
	min = stoi(stime.substr(3, 2));
	sec = stoi(stime.substr(6, 2));
}

// Return MM/DD/YYYY HH:MM:SS
string DateTime::toString() {
	string stime = !isEmpty() ? (" " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec)) : "";
	return this->getDate().toString() + stime;
}

bool DateTime::operator>(const DateTime& otherD) const {
	return (hr > otherD.hr && min > otherD.min && sec > otherD.sec)
		&& DateType::operator>(otherD);
}
bool DateTime::operator<(const DateTime& otherD) const {
	//if either this > other or this = other, then this can't be < other
	return !(*this > otherD || *this == otherD);
}
bool DateTime::operator>=(const DateTime& otherD) const {
	//if this !< than other, then this must be > or =
	return !(*this < otherD);
}
bool DateTime::operator<=(const DateTime& otherD) const {
	return !(*this > otherD);
}
bool DateTime::operator==(const DateTime& otherD) const {
	return (hr == otherD.hr && min == otherD.min && sec == otherD.sec)
		&& DateTime::operator==(otherD);
}
bool DateTime::operator!=(const DateTime& otherD) const {
	return !(*this == otherD);
}
