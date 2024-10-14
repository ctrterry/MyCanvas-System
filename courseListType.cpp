#include <iostream>
#include <string>
#include "courseListType.h"
#include "course.h"

using namespace std;

CourseListType::CourseListType() {
	ascending = false;
	initFieldIndex();
}

void CourseListType::initFieldIndex() {
	// Must be ordered by Course::fieldIndex
	fieldIndexMenu.setName("Sort By Field Name");
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_TERM) + ") term");		//1
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_YEAR) + ") year");		//2
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_START_DATE) + ") startDate");	//3
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_END_DATE) + ") endDate");	//4
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_NAME) + ") name");		//5
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_SECTION) + ") section");	//6
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_ID) + ") Course Id");	//7
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_MEETING_DAYS) + ") meetDays");	//8
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_LOCATION) + ") location");	//9
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_MEETING_INFO) + ") meetInfo");	//10
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_INSTRUCTOR) + ") instructor");	//11
	fieldIndexMenu.addOption(to_string(COURSE_FIELD_INDEX::COURSE_UNITS) + ") units");		//12
}

void CourseListType::sortBy() {
	// select a fieldIndex for field name
	Course::fieldIndex = fieldIndexMenu.getOptionIndex();
	
	// toggle ascending and descending order
	cout << "Enter (0=default ascending; 1=descending): ";
	string s;
	cin.ignore(); // ignore empty space
	getline(cin, s);
	ascending = (s.empty() || s == "0");


	// do sortBy fieldIndex
	sort(ascending);	
}

Course* CourseListType::find(string value) {		
	// select fieldIndex
	Course::fieldIndex = fieldIndexMenu.getOptionIndex();

	// Set field value for Course to search
	Course c;
	c.setFieldValue(value);
	int location = search(c);

	// return nullptr for not found
	return location > 0 ? &list[location] : nullptr;
}

Course* CourseListType::at(int location) {
	Course* p = nullptr;
	if (location < 0 || location >= length) {
		cout << "The location of the item to be retrieved is "
			<< "out of range" << endl;
	} else {
		p = &list[location];
	}
	return p;
}


void CourseListType::print() {
	Course* p = nullptr;
	for (int i = 1; i <= listSize(); i++) {
		p = at(i - 1);
		cout << *p; // to osSteam out
	}
}