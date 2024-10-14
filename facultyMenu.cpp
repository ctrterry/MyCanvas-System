#include <fstream>
#include <sstream>
#include <string>
#include "menu.h"
#include "faculty.h"
#include "facultyMenu.h"
#include "utils.h"
#include "unorderedArrayListType.h"
#include "myOpenFilesExceptionHandle.hpp"

FacultyMenu::FacultyMenu()
    : Menu("Course Menu") {
    addOption("1) Faculty list");   // Lab 5 - sortBy any field in class Person
    addOption("2) View faculty contact");
    addOption("3) Add a faculty");
    addOption("4) Edit a faculty");
    addOption("5) Delete a faculty");
    addOption("x) Exit");

    list = new UnorderedArrayListType<Faculty>();
    init();
};

FacultyMenu::~FacultyMenu() {    
    delete list;
    inFile.close();
}

void FacultyMenu::init() {
    string fileName = FACULTY_DATA;
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
            cout << "Faculty Data: " << op.what() << "Eg, faculty_data.csv " << endl;
            fileName = getUserFileInput();
        }
    }
    
	// sets variables for strings in course file
	string id;
	string firstName;
	string lastName;
	string department;
	string address;
	string city;
	string state;
	string zip;
	string email;
	string number;

	// reads file and set variables
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, department, ',');
		getline(ss, address, ',');
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, email, ',');
		getline(ss, number, ',');

		// sets variables to the faculty array 
		Faculty f;
		Faculty* _faculty = &f;
		_faculty->setId(stoi(id));
		_faculty->setFirstName(firstName);
		_faculty->setLastName(lastName);
		_faculty->setDepartment(department);
		_faculty->setAddress(address);
		_faculty->setCity(city);
		_faculty->setState(state);
		_faculty->setZip(zip);
		_faculty->setEmail(email);
		_faculty->setPhone(number);

		list->insertEnd(*_faculty);
	}

    inFile.clear();

	list->sort(true);
}

void FacultyMenu::doList() {
	Menu c("List of Faculty");
	Faculty f;
	Faculty* p = &f;

	// retrieves each element from faculty array p
	for (int i = 1; i <= list->listSize(); i++) {
		list->retrieveAt(i - 1, *p);
		c.addOption(to_string(p->getId()) + " " + p->getFirstName() + " " + p->getLastName() + " " + p->getDepartment() \
			+ " " + p->getAddress() + " " + p->getCity() + " " + p->getState() + " " + p->getZip() + " " + p->getEmail() \
			+ " " + p->getPhone());
	}

	// user input to choose an array element
	int input = c.getInput();
	list->retrieveAt(input - 1, *p);
	this->selectedFaculty(*p);
}

void FacultyMenu::doView() {
	// checks if array is empty, if it is it fills it
	if (pFaculty == nullptr) {
		doList();
	}

	// prints array
	pFaculty->print();
}

void FacultyMenu::doAdd() {
	Faculty f;
	Faculty* p = &f;

	// sets varibles for elements for array
	string id;
	string firstName;
	string lastName;
	string department;
	string address;
	string city;
	string state;
	string zip;
	string email;
	string number;


	// user prompt to enter elements of the array to add
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter faculty's first name: ";
	cin.ignore();
	getline(cin, firstName);
	cout << "Enter faculty's last name: ";
	cin.ignore();
	getline(cin, lastName);
	cout << "Enter department name: ";
	getline(cin, department);
	cout << "Enter address: ";
	getline(cin, address);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter state: ";
	cin >> state;
	cout << "Enter zip code: ";
	cin >> zip;
	cout << "Enter email: ";
	cin >> email;
	cout << "Enter phone number: ";
	cin >> number;


	// new variables are set to the course array
	p->setId(stoi(id));
	p->setFirstName(firstName);
	p->setLastName(lastName);
	p->setDepartment(department);
	p->setAddress(address);
	p->setCity(city);
	p->setState(state);
	p->setZip(zip);
	p->setEmail(email);
	p->setPhone(number);

	// variables are added to the array
	list->insertEnd(*p);
}

void FacultyMenu::doEdit() {
	// checks if course array is empty, adds elements
	if (pFaculty == nullptr) {
		doList();
	}
	Faculty* p = pFaculty;
	string temp;


	// promts user to input new variables for each element of the course array
	cout << "Enter new id or default (" + to_string(p->getId()) + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setId(stoi(temp));
	}

	cout << "Enter new first name or default (" + p->getFirstName() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setFirstName(temp);
	}

	cout << "Enter new last name or default (" + p->getLastName() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setLastName(temp);
	}

	cout << "Enter new department name or default (" + p->getDepartment() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setDepartment(temp);
	}

	cout << "Enter new address or default (" + p->getAddress() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setAddress(temp);
	}

	cout << "Enter new city or default (" + p->getCity() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setCity(temp);
	}

	cout << "Enter new state or default (" + p->getState() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setState(temp);
	}

	cout << "Enter new zip or default (" + p->getZip() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setZip(temp);
	}

	cout << "Enter new email or default (" + p->getEmail() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setEmail(temp);
	}

	cout << "Enter new phone number or default (" + p->getPhone() + "):";
	getline(cin, temp);

	if (!temp.empty()) {
		p->setPhone(temp);
	}


	// prints out editted array
	cout << "Show faculty details: " << endl;
	p->print();
	cout << endl;
}

void FacultyMenu::doDelete() {
	// checks if array is empty, fills
	if (pFaculty == nullptr) {
		doList();
	}

	// removes element from the array
	list->remove(*pFaculty);
}

Faculty* FacultyMenu::find(Faculty& f) {
	int index = list->search(f);	
	list->retrieveAt(index, f);
	return &f;
}

/**
* Save to file
*/
void FacultyMenu::doSave() {
	// TODO
}
