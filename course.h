#pragma once
#include <string>
#include "faculty.h"
#include "dateTime.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum COURSE_FIELD_INDEX {
	COURSE_TERM = 1,
	COURSE_YEAR = 2,
	COURSE_START_DATE = 3,
	COURSE_END_DATE = 4,
	COURSE_NAME = 5,
	COURSE_SECTION = 6,
	COURSE_ID = 7,
	COURSE_MEETING_DAYS = 8,
	COURSE_LOCATION = 9,
	COURSE_MEETING_INFO = 10,
	COURSE_INSTRUCTOR = 11,
	COURSE_UNITS = 12
};

class Course {
    friend ostream& operator<<(ostream& os, Course& cs);
	friend istream& operator>>(istream& in, Course& c);

public:
	Course();
	~Course();

	//Mutator functions
	void setTerm(string t) { term = t; };
	void setYear(int y) { year = y; };
	void setStartDate(string s) { startDate.setDate(s); };
	void setEndDate(string e) { endDate.setDate(e); };
	void setName(string n) { name = n; };
	void setSection(string s) { section = s; };
	void setId(string i) { id = i; };
	void setMeetDays(string m) { meetDays = m; };
	void setLocation(string l) { location = l; };
	void setMeetInfo(string m) { meetInfo = m; };	
	void setUnits(int u) { units = u; };
	void setInstructor(string id) { instructor.setId(stoi(id)); };
	void setInstructor(Faculty& f) { instructor = f; }

	string getName() const {
		return name;
	};

	string getSection() const {
		return section;
	};

	string getTerm() const {
		return term;
	};

	int getYear() const {
		return year;
	};

	Faculty& getInstructor() {
		return instructor;
	}

	//Return the course information as a string in CSV format
	string toCSV();
	//Print to console the course information in nice formatting
	void print();

	
	//Overloaded operators
	bool operator>=(const Course&) const;
	bool operator<=(const Course&) const;
	bool operator<(const Course&) const;
	bool operator>(const Course&) const;
	bool operator==(const Course&) const;
	bool operator!=(const Course&) const;

	static int fieldIndex; // See COURSE_FIELD_INDEX
	void setFieldValue(string value);

private:
     string term;
	 int year;
	 DateTime startDate;
	 DateTime endDate;
	 string name;
	 string section;
 	 string id;
 	 string meetDays;
	 string location;
	 string meetInfo;
	 Faculty instructor;
	 int units;
};

