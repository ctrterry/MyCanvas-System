#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "menu.h"
#include "courseMenu.h"
//#include "unorderedArrayListType.h"
#include "courseListType.h"
#include "utils.h"
#include "myOpenFilesExceptionHandle.hpp"
#include "myIntergerExceptionHandle.hpp"

using namespace std;

CourseMenu::CourseMenu()
    : Menu("Course Menu") {
    addOption("1) List of Course");
    addOption("2) Select a course from the list of courses"); // Lab 5 - 1) sortBy any field in class Course; 2) use FacultyMenu to set the faculty info
    addOption("3) View course details");
    addOption("4) Add a course");   // Lab 5 - use FacultyMenu to select a faculty to add
    addOption("5) Edit a course");  // Lab 5 - use FacultyMenu to select a faculty to edit
    addOption("6) Delete a course");
    addOption("x) Exit");

    pCourse = nullptr;    
    list = new CourseListType();    // Lab 5 UnorderedArrayListType to CourselistType
    init();
};

CourseMenu::~CourseMenu() {    
    delete list;
    inFile.close();
}

/**
* 
* Read/populate course_data.csv into the list
*/
void CourseMenu::init() {
    string fileName = COURSE_DATA;
    bool valid = false ;
    int attempt = 0;
    while(!valid){
        attempt++;
        if(attempt == 3){
            valid = true;
        }
            try{
                if(openFile(inFile, fileName)){
                    break;
                }
                else {
                    throw myOpenFilesExceptionHandle();
                }
            }
            catch (myOpenFilesExceptionHandle & op){
                cout << "Course Data: " << op.what() << "Eg, course_data.csv " << endl;
                fileName = getUserFileInput();
                fileName = macFileNamePrefixed() + fileName;
            }
    }

    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id;
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        
        try{
            
            getline(ss, term, ',');
            getline(ss, year, ',');
            getline(ss, startDate, ',');
            getline(ss, endDate, ',');
            getline(ss, name, ',');
            getline(ss, section, ',');
            getline(ss, id, ',');
            getline(ss, meetDays, ',');
            getline(ss, location, ',');
            getline(ss, meetInfo, ',');
            getline(ss, instructor, ',');
            getline(ss, units, ',');
            Course c;
            Course* p = &c;
            p->setTerm(term);
            
            if(Is_Number(year)){
                p->setYear(stoi(year));
            }else{
                throw myIntergerExceptionHandle("Years Error");
            }
            p->setStartDate(startDate);
            p->setEndDate(endDate);
            p->setName(name);
            p->setSection(section);
            p->setId(id);
            p->setMeetDays(meetDays);
            p->setLocation(location);
            p->setMeetInfo(meetInfo);
            p->setInstructor(instructor);
            // Lab 5 - find and update faculty
            Faculty* f = facultyMenu.find(p->getInstructor());
            p->setInstructor(*f);
            if(Is_Number(units)){
                p->setUnits(stoi(units));
            }else{
                throw myIntergerExceptionHandle("Units Error");
            }
            list->insertEnd(*p);
        }
        catch( exception& e){
            cout << "Exception " << e.what() << endl;
            cout << "Input Correct Year: ";
            cin >> year;
            continue;
        }
        catch (myIntergerExceptionHandle &c){
            cout << c.what() << "\nShowing Error Data: " << year << endl;
            cout << "Input correct Infor: ";
            cin >> year;
            continue;
        }
    }
    inFile.clear();
}

void CourseMenu::doList() {
    Menu menu("List of Courses");
    Course* p = nullptr;
    for (int i = 1; i <= list->listSize(); i++) {
        p = list->at(i - 1);
        menu.addOption(p->getTerm() + " " + to_string(p->getYear()) + " " + p->getSection() + " " + p->getName());
    }
    int input = menu.getInput();
    p = list->at(input - 1);
    this->selectedCourse(*p);
}

void CourseMenu::doView() {
    if (pCourse == nullptr) {        
        doList();
    }
    printCourseHeader();
    pCourse->print();
}

void CourseMenu::doAdd() {
    //Course* p = new Course();
    Course c;    
    Course* p = &c;

    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id;
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;

    cout << "Enter Term: ";
    cin >> term;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter start date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter end date (MM/DD/YYYY): ";
    cin >> endDate;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter section: ";
    cin >> section;
    cout << "Enter course Id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter meeting days: ";
    cin >> meetDays;
    cout << "Enter meeting location: ";
    cin >> meetInfo;
    cout << "Enter instructor id: ";
    cin >> instructor;
    cout << "Enter units: ";
    cin >> units;
    p->setTerm(term);
    p->setYear(stoi(year));
    p->setStartDate(startDate);
    p->setEndDate(endDate);
    p->setName(name);
    p->setSection(section);
    p->setId(id);
    p->setMeetDays(meetDays);
    p->setLocation(location);
    p->setMeetInfo(meetInfo);
    p->setInstructor(instructor);    
    // Lab 5 - find and update faculty
    Faculty* f = facultyMenu.find(p->getInstructor());
    p->setInstructor(*f);
    p->setUnits(stoi(units));
    list->insertEnd(*p);
}

void CourseMenu::doEdit() {
    if (pCourse == nullptr) {
        doList();
    }
    Course* p = pCourse;

    string temp;
    cout << "Enter new term or default  (" + p->getTerm() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        p->setTerm(temp);
    }
    
    p->print();
}

void CourseMenu::doDelete() {
    if (pCourse == nullptr) {
        doList();
    }
    list->remove(getSelectedCourse());
}

void CourseMenu::doFacultyMenu() {    
    char option = FACULTY_MENU_OPTION::FACULTY_EDIT;
    do {
        option = facultyMenu.getOption();

        if (option == FACULTY_MENU_OPTION::FACULTY_LIST) {
            facultyMenu.doList();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_VIEW) {
            facultyMenu.doView();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_ADD) {
            facultyMenu.doAdd();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EDIT) {
            facultyMenu.doEdit();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_DELETE) {
            facultyMenu.doDelete();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EXIT) {
            // TODO facultyMenu.doSave();
            cout << "Exiting Faculty Menu" << endl;
        }
    } while (option != FACULTY_MENU_OPTION::FACULTY_EXIT);
}

void CourseMenu::doSortedList() {    
    // Sortby the list
    list->sortBy();

    // show list
    printCourseHeader();
    list->print();
}

/**
* Save to file
*/
void CourseMenu::doSave() {
    cout << "\n***** Data Saving Into a New Files *****" << endl;
    fstream file;
    cout << "\nProvide a New Files Name:  ";
    char fileName[100];
    cin>>fileName;
    cin.ignore();
    file.open(fileName,ios::out|ios::in|ios::app);
    if (file.is_open()) {
        Course *p = nullptr;
        for (int i = 1; i <= list->listSize(); i++) {
            p = list->at(i - 1);
            file << p->toCSV() << "\n";
        }
        cout << "Saving... " << macFileNamePrefixed() + fileName << endl;
    }
    else {
        cerr << "Failed to open file : " << COURSE_DATA
        << " (errno " << errno << ")" << endl;
    }
    cout << "Save!!!" << endl << endl;
    file.close();
}
