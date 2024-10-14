#pragma once
#include <string>
#include "menu.h"
#include "course.h"
#include "unorderedArrayListType.h"

using namespace std;

class CourseListType : public UnorderedArrayListType<Course> {

public:
	CourseListType();

	void sortBy();
	Course* at(int location);
	Course* find(string searchName);
	void print();

private:
	bool ascending; // use to toggle sortBy ascending and descending order
	void initFieldIndex();
	Menu fieldIndexMenu;

};
