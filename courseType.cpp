#include <string>
#include "course.h"
#include "faculty.h"
#include "dateTime.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int Course::fieldIndex = COURSE_FIELD_INDEX::COURSE_ID; // default Course::id

//Default constructor
Course::Course() {
	term ="";
	year = 0;
	name = "";
	section = "";
	id = "-1";
	meetDays = "";
	location = "";
	meetInfo = "";
	units = 0;
}

Course::~Course() {
	// TODO...
    
}

//Return the course information as a string in CSV format
string Course::toCSV() {
	return term + "," + to_string(year) + "," + startDate.toString() + ","
		+ endDate.toString() + "," + name + "," + section + ","
		+ id + "," + meetDays + "," + location + ","
		+ meetInfo + "," + instructor.getLastName() + "," + to_string(units);
}


//Print to console the course information in nice formatting
void Course::print()  {
	cout << left << setw(8) << term << setw(5) << year << setw(12) << startDate.getDate().toString() << setw(12)
		<< endDate.getDate().toString() << setw(32) << name << setw(10) << section
		<< setw(10) << id << setw(8) << meetDays << setw(10) << location
		<< setw(10) << meetInfo << setw(15) << instructor.getLastName() << setw(5) << units << endl;
}

bool Course::operator==(const Course& otherC) const{
	bool valid = false;
	if (fieldIndex == COURSE_TERM) {
		valid = term == otherC.term;
	} else if (fieldIndex == COURSE_YEAR) {
		valid = year == otherC.year;
	} else if (fieldIndex == COURSE_START_DATE) {
		valid = startDate == otherC.startDate;
	} else if (fieldIndex == COURSE_END_DATE) {
		valid = endDate == otherC.endDate;
	} else if (fieldIndex == COURSE_NAME) {
		valid = name == otherC.name;
	} else if (fieldIndex == COURSE_SECTION) {
		valid = section == otherC.section;
	} else if (fieldIndex == COURSE_ID) {
		valid = id == otherC.id;
	} else if (fieldIndex == COURSE_MEETING_DAYS) {
		valid = meetDays == otherC.meetDays;
	} else if (fieldIndex == COURSE_LOCATION) {
		valid = location == otherC.location;
	} else if (fieldIndex == COURSE_MEETING_INFO) {
		valid = meetInfo == otherC.meetInfo;
	} else if (fieldIndex == COURSE_UNITS) {
		valid = units == otherC.units;
	}
	return valid;
}

bool Course::operator!=(const Course& otherC) const{
	return !(*this == otherC);
}

bool Course::operator>=(const Course& otherC) const{
	return !(*this < otherC);
}
bool Course::operator<=(const Course& otherC) const{
	return !(*this > otherC);
}
bool Course::operator<(const Course& otherC) const{
	bool valid = false;
	if (fieldIndex == COURSE_TERM) {
		valid = term < otherC.term; 
	} else if (fieldIndex == COURSE_YEAR) {
		valid = year < otherC.year;
	} else if (fieldIndex == COURSE_START_DATE) {
		valid = startDate < otherC.startDate;
	} else if (fieldIndex == COURSE_END_DATE) {
		valid = endDate < otherC.endDate;
	} else if (fieldIndex == COURSE_NAME ) {
		valid = name < otherC.name;
	} else if (fieldIndex == COURSE_SECTION) {
		valid = section < otherC.section;
	} else if (fieldIndex == COURSE_ID) {
		valid = id < otherC.id;
	} else if (fieldIndex == COURSE_MEETING_DAYS) {
		valid = meetDays < otherC.meetDays;
	} else if (fieldIndex == COURSE_LOCATION) {
		valid = location < otherC.location;
	} else if (fieldIndex == COURSE_MEETING_INFO) {
		valid = meetInfo < otherC.meetInfo;
	} else if (fieldIndex == COURSE_UNITS) {
		valid = units < otherC.units;
	}
	return valid;
}
bool Course::operator>(const Course& otherC) const{
	// See Course::operator<
	return !(*this < otherC || *this == otherC);
}

void Course::setFieldValue(string value) {
	if (fieldIndex == COURSE_TERM) {
		term = value;
	} else if (fieldIndex == COURSE_YEAR) {
		year = stoi(value);
	} else if (fieldIndex == COURSE_START_DATE) {
		setStartDate(value);
	} else if (fieldIndex == COURSE_END_DATE) {
		setEndDate(value);
	} else if (fieldIndex == COURSE_NAME) {
		name = value;
	} else if (fieldIndex == COURSE_SECTION) {
		section = value;
	} else if (fieldIndex == COURSE_ID) {
		id = stoi(value);
	} else if (fieldIndex == COURSE_MEETING_DAYS) {
		meetDays = value;
	} else if (fieldIndex == COURSE_LOCATION) {
		location = value;
	} else if (fieldIndex == COURSE_MEETING_INFO) {
		meetInfo = value;
	} else if (fieldIndex == COURSE_UNITS) {
		units = stoi(value);
	}
}

ostream& operator<<(ostream& osObject, Course& c) {
	osObject << left << setw(8) << c.term << setw(5) << c.year << setw(12) << c.startDate.getDate().toString() << setw(12)
		<< c.endDate.getDate().toString() << setw(32) << c.name << setw(10) << c.section
		<< setw(10) << c.id << setw(8) << c.meetDays << setw(10) << c.location
		<< setw(10) << c.meetInfo << setw(15) << c.instructor.getLastName() << setw(5) << c.units << endl;
	return osObject;
}
