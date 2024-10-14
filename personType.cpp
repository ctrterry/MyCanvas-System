#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"

using namespace std;

Person::Person(string fullname) {
    setFullName(fullname);
}

//Copy constructor
Person::Person(const Person& otherObject){
    copy(otherObject);
}

void Person::copy(const Person& otherObject) {
	id = otherObject.getId();
	firstName = otherObject.getFirstName();
	lastName = otherObject.getLastName();
	address = otherObject.getAddress();
	city = otherObject.getCity();
	state = otherObject.getState();
	zip = otherObject.getZip();
	phone = otherObject.getPhone();
	email = otherObject.getEmail();
}

void Person::setFullName(string name /** firstname middle lastname */) {
    int pos, i = 0;
    // firstname, middle, lastname
    string names[3];
    do {
        pos = name.find(" ");
        if (pos > 0) {
            names[i++] = name.substr(0, pos);
            name = name.substr(pos + 1);
        }
        else {
            names[2] = name;
        }
    } while (pos > 0);
    setFirstName(names[0]);
    setMiddleName(names[1]);
    setLastName(names[2]);
}