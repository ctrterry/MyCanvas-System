#include "menu.h"
#include "mainMenu.h"
#include "assignmentMenu.h"
#include "announcementMenu.h"
#include "discussionMenu.h"
#include "studentMenu.h"

MainMenu::MainMenu()
    : Menu("My Canvas Menu") {
    addOption("1) Home");
    addOption("2) Announcements");
    addOption("3) Assignments");
    addOption("4) Discussions");
    addOption("5) Grades");
    addOption("6) Quizzes");
    addOption("7) People");
    addOption("x) Logout");
};

void MainMenu::doAssignments() {
	char option = ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT;
	do {
		option = assignmentMenu.getOption();

		if (option == ASSIGNMENT_MENU_OPTION::LIST_ALL) {
			assignmentMenu.doList();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::LIST_PENDING) {
			assignmentMenu.doListPending();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::LIST_COMPLETED) {
			assignmentMenu.doListCompleted();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::VIEW) {
			assignmentMenu.doView();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::ADD) {
			assignmentMenu.doAdd();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::EDIT) {
			assignmentMenu.doEdit();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::DELETE) {
			assignmentMenu.doDelete();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT) {
			cout << "Exiting Assignments Menu" << endl;
			assignmentMenu.doSave();
		}
	} while (option != ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT);
}

void MainMenu::doAnnouncements() {
	char option = ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_EXIT;
	do {
		option = announcementMenu.getOption();

		if (option == ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_LIST) {
			announcementMenu.doList();
		}
		else if (option == ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_VIEW) {
			announcementMenu.doView();
		}
		else if (option == ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_ADD) {
			announcementMenu.doAdd();
		}
		else if (option == ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_EDIT) {
			announcementMenu.doEdit();
		}
		else if (option == ANNOUNCEMENT_MENU_OPTION::ANNOUNCEMENT_DELETE) {
			announcementMenu.doDelete();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT) {
			cout << "Exiting Announcements Menu" << endl;
			announcementMenu.doSave();
		}
	} while (option != ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT);
}

void MainMenu::doDiscussions() {
	char option = DISCUSSION_MENU_OPTION::DISCUSSION_EXIT;
	do {
		option = discussionMenu.getOption();

		if (option == DISCUSSION_MENU_OPTION::DISCUSSION_LIST) {
			discussionMenu.doList();
		}		
		else if (option == DISCUSSION_MENU_OPTION::DISCUSSION_VIEW) {
			discussionMenu.doView();
		}
		else if (option == DISCUSSION_MENU_OPTION::DISCUSSION_ADD) {
			discussionMenu.doAdd();
		}
		else if (option == DISCUSSION_MENU_OPTION::DISCUSSION_EDIT) {
			discussionMenu.doEdit();
		}
		else if (option == DISCUSSION_MENU_OPTION::DISCUSSION_DELETE) {
			discussionMenu.doDelete();
		}
		else if (option == DISCUSSION_MENU_OPTION::DISCUSSION_EXIT) {
			cout << "Exiting Discussion Menu" << endl;
			discussionMenu.doSave();
		}
	} while (option != DISCUSSION_MENU_OPTION::DISCUSSION_EXIT);
}

void MainMenu::doStudentMenu() {
	char option = STUDENT_MENU_OPTION::STUDENT_EXIT;
	do {
		option = studentMenu.getOption();

		if (option == STUDENT_MENU_OPTION::STUDENT_LIST) {
			studentMenu.doList();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_VIEW) {
			studentMenu.doView();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_ADD) {
			studentMenu.doAdd();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EDIT) {
			studentMenu.doEdit();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_DELETE) {
			studentMenu.doDelete();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EXIT) {			
			cout << "Exiting Students Menu" << endl;
			studentMenu.doSave();
		}
	} while (option != STUDENT_MENU_OPTION::STUDENT_EXIT);
}