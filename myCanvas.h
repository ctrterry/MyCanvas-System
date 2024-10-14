#pragma once
#include <vector>
#include <string>
#include "home.h"
#include "announcement.h"
#include "discussion.h"
#include "assignment.h"
#include "grade.h"
#include "syllabus.h"
#include "student.h"
#include "person.h"
#include "faculty.h"
#include "course.h"
#include "loginMenu.h"
#include "courseMenu.h"
#include "mainMenu.h"
#include "utils.h"

using namespace std;

class MyCanvas {
public:
	MyCanvas();
	~MyCanvas();

    
	bool doLogin();
	void doLogout();
	bool doCourseMenu();
	void doMainMenu();
    bool checkLoginStatus(bool valid){
        if(valid == true ){
            loginMenu.doLoginDateTime();
        }
        return valid;
    }

	Course& getSelectedCourse() {
		return courseMenu.getSelectedCourse();
	};

private:	
	LoginMenu loginMenu;
	CourseMenu courseMenu;
	MainMenu mainMenu;	
};
