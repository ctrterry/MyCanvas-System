#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "menu.h"
#include "assignment.h"
#include "assignmentMenu.h"
#include "unorderedArrayListType.h"
#include "utils.h"
#include "myOpenFilesExceptionHandle.hpp"
#include "myIntergerExceptionHandle.hpp"

using namespace std;

AssignmentMenu::AssignmentMenu()
    : Menu("Assignments Menu") {
    addOption("1) List all assignments");
    addOption("2) List pending assignments");
    addOption("3) List completed assignments");
    addOption("4) View");
    addOption("5) Add");
    addOption("6) Edit");
    addOption("7) Delete");
    addOption("x) Exit");

    pAssignment = nullptr;
    list = new UnorderedArrayListType<Assignment*>();    
    init();
};

AssignmentMenu::~AssignmentMenu() {
    int i = 0;
    while (i < list->listSize()) {
        Assignment* p;
        list->retrieveAt(i, p);
        delete p;
        i++;
    }
    delete list;
    inFile.close();
}

/**
*
* Read/populate course_data.csv into the list
*/
void AssignmentMenu::init() {       
    string fileName = ASSIGNMENT_DATA;
    bool valid = false ;
    int attempt = 0;
    while(!valid){
        attempt++;
        if(attempt < 3){
            valid = true;
        }
        try{
            // return true or False. for openFile .
            if(openFile(inFile, fileName)){
                break;
            }
            else {
                throw myOpenFilesExceptionHandle();
            }
        }
        catch (myOpenFilesExceptionHandle & op){
            cout << "Assignment Data: " << op.what() << "Eg, assignment_data.csv " << endl;
            fileName = getUserFileInput();
        }
    }

    string name;
    string availableDate;
    string dueDate;
    string possiblePoints;
    string points;
    string status;  // 1=Yes; 0=No

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, availableDate, ',');
        getline(ss, dueDate, ',');
        getline(ss, possiblePoints, ',');
        getline(ss, points, ',');
        getline(ss, status, ',');

        Assignment* p = new Assignment();

        try{
            p->setName(name);
            p->setAvailableDate(availableDate);
            p->setDueDate(dueDate);
            if(Is_Number(possiblePoints)){
                p->setPossiblePoint(stoi(possiblePoints));
            }else{
                throw myIntergerExceptionHandle("possible Points Error");
            }
            if(Is_Number(points)){
                p->setPoint(stoi(points));
            }else{
                throw myIntergerExceptionHandle("Points Error");
            }
            if(Is_Number(status)){
                p->setStatus(stoi(status));
            }else{
                throw myIntergerExceptionHandle("Statues Error");
            }
            list->insertEnd(p);
        }
        catch (myIntergerExceptionHandle &c){
            cout << c.what() << "\nShowing Error Data: " << points << endl;
            cout << "Input correct Infor: ";
            cin >> points;
            continue;
        }
    }
    inFile.clear();
}

void AssignmentMenu::doList() {
    Menu c("Assignments");
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        c.addOption(p->getName());
    }
    int input = c.getInput();
    list->retrieveAt(input - 1, p);
    this->setAssignment(*p);
    cout << endl;
}

void AssignmentMenu::doListPending() {
    UnorderedArrayListType<Assignment*> tmpList;
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (!p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }    

    cout << "***** View Pending Assignments *****" << endl;
    if (tmpList.listSize() != 0) {
        Assignment::printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    } else {
        cout << "No Pending Assignments" << endl;
    }
    cout << endl;
}

void AssignmentMenu::doListCompleted() {
    UnorderedArrayListType<Assignment*> tmpList;
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }
    cout << "***** View Completed Assignments *****" << endl;
    if (tmpList.listSize() != 0) {
        Assignment::printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    }
    else {
        cout << "No Completed Assignments" << endl;
    }
    cout << endl;
}

void AssignmentMenu::doView() {
    if (pAssignment == nullptr) {
        doList();
    }
    cout << "***** View Selected Assignment *****" << endl;
    Assignment a = getSelectedAssignment();
    a.printHeader();
    cout << a << endl << endl;
}

void AssignmentMenu::doAdd() {
    cout << "***** Add New Assignment *****" << endl;
    Assignment* p = new Assignment();
    cin >> *p;
    list->insertEnd(p);
}

void AssignmentMenu::doEdit() {
    if (pAssignment == nullptr) {
        doList();
    }
    cout << "***** Edit Selected Assignment *****" << endl;
    if (pAssignment != nullptr) {
        cin >> *pAssignment;
    }
    else {
        // Users need to select an assignment to edit
        doList();
        doEdit();
    }
    cout << endl;
}

void AssignmentMenu::doDelete() {
    cout << "***** Delete Assignment *****" << endl;
    if (pAssignment == nullptr) {
        doList();
    }
    string name = pAssignment->getName();
    list->remove(pAssignment);
    pAssignment = nullptr;
    cout << name << ", deleted!" << endl << endl;
}

/**
* Save to file
*/
void AssignmentMenu::doSave() {
    
    // Give User a Options that Saving in Existing Files or Creative a new Files.
        fstream file;
        cout << "Provide a New Files Name:  ";
        char fileName[100];
        cin>>fileName;
        cin.ignore();
        file.open(fileName,ios::out|ios::in|ios::app);
        if (file.is_open()) {
            Assignment* p;
            for (int i = 1; i <= list->listSize(); i++) {
                list->retrieveAt(i - 1, p);
                file << p->toCSV() << endl;
            }
            cout << "Saving... " << macFileNamePrefixed() + fileName << endl;
        }
        else {
            cerr << "Failed to open file : " << ASSIGNMENT_DATA
            << " (errno " << errno << ")" << endl;
        }
        cout << "Save!!!" << endl << endl;
        file.close();
    
   
}
