#include <iostream>
#include <string>
#include <iomanip>
#include "person.h"
#include "student.h"

using namespace std;

//Default constructor
//Implicitly calls PersonType's default constructor
Student::Student(const Person& otherObject)
	: Person(otherObject) {
}

Student::Student() {
	setId(-1);
}

string Student::getFullName() {
	return getFirstName() + " " + getMiddleName() + getLastName();
}


void Student::print() const {
	cout << left 
		<< setw(5) << getId()
		<< setw(15)	<< getFirstName()
		//<< setw(5) << getMiddleName()
		<< setw(15)	<< getLastName()
		<< setw(25)	<< getAddress()
		<< setw(15)	<< getCity()
		<< setw(5)	<< getState()
		<< setw(15)	<< getPhone()
		<< setw(20)	<< getEmail()
		<< endl;
}

Student& Student::operator=(const Student& other) {
	setId(other.getId());
	setFirstName(other.getFirstName());
	setMiddleName(other.getMiddleName());
	setLastName(other.getLastName());
	setAddress(other.getAddress());
	setCity(other.getCity());
	setState(other.getState());
	setZip(other.getZip());
	setPhone(other.getPhone());
	setEmail(other.getEmail());

	return *this;
}

//Overloaded to allow sorting
bool Student::operator==(const Student& otherS) const{
	return getId() == otherS.getId();
}
bool Student::operator!=(const Student& otherS) const{
	return !(*this == otherS);
}

bool Student::operator>(const Student& otherS) const{
	return getId() > otherS.getId();
}
bool Student::operator<(const Student& otherS) const{
	return !(*this > otherS || *this == otherS);
}
bool Student::operator>=(const Student& otherS) const{
	return !(*this < otherS);
}
bool Student::operator<=(const Student& otherS) const{
	return !(*this > otherS);
}


