#include <vector>
#include "myCanvas.h"
#include "loginMenu.h"
#include "courseMenu.h"
#include "studentMenu.h"
#include "mainMenu.h"


using namespace std;

MyCanvas::MyCanvas() {
}

MyCanvas::~MyCanvas() {

}

bool MyCanvas::doLogin() {
	char option = loginMenu.getOption();
	switch (option) {
		case LOGIN_MENU_OPTION::LOGIN:
			//return loginMenu.doLogin();
            return checkLoginStatus(loginMenu.doLogin());
		case LOGIN_MENU_OPTION::CREATE:
			loginMenu.doCreate();
            loginMenu.getOption();
            return loginMenu.doLogin();
		case LOGIN_MENU_OPTION::RESET:
			loginMenu.doReset();
            return loginMenu.doLogin();
		case LOGIN_MENU_OPTION::EXIT:
            doLogout();
            loginMenu.doSave();
			cout << "Exiting Login Menu" << endl;
			return false;
		default: {}
	}

	return false;
}

void MyCanvas::doLogout() {
    loginMenu.doLogout();
}

bool MyCanvas::doCourseMenu() {
	char option = COURSE_MENU_OPTION::COURSE_EXIT;
	do {
		option = courseMenu.getOption();

		if (option == COURSE_MENU_OPTION::COURSE_LIST) {
            courseMenu.doList();
		}
        else if (option == COURSE_MENU_OPTION::COURSE_LIST_BY) {
            courseMenu.doSortedList();
        }
		else if (option == COURSE_MENU_OPTION::COURSE_VIEW) {
			courseMenu.doView();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_ADD) {
			courseMenu.doAdd();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EDIT) {
			courseMenu.doEdit();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_DELETE) {
			courseMenu.doDelete();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EXIT) {
			courseMenu.doSave();
			cout << "Exiting Course Menu" << endl;
		}
	} while (option != EXIT);

	return courseMenu.isSelectedCourse();
}

void MyCanvas::doMainMenu() {	
	char option = MAIN_MENU_OPTION::MAIN_MENU_EXIT;
	do {
		option = mainMenu.getOption();

		if (option == MAIN_MENU_OPTION::MAIN_MENU_HOME){
			//TODO mainMenu.doHome();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_ANNOUNCEMENT) {
			mainMenu.doAnnouncements();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_DISCUSSION) {
			mainMenu.doDiscussions();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_ASSIGNMENT) {
			mainMenu.doAssignments();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_QUIZ) {
			//TODO mainMenu.doQuiz();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_STUDENT) {				
			mainMenu.doStudentMenu();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_SYLLABUS) {
			// TODO mainMenu.doSyllabus();
            
		} // else EXIT
        else{
            loginMenu.doSave();
            doLogout();
            cout << "Exiting My Canvas Menu" << endl;
        }
	} while (option != MAIN_MENU_OPTION::MAIN_MENU_EXIT);
}
