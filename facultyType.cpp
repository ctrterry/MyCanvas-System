#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "faculty.h"

using namespace std;

//Default constructor
//Implicitly calls PersonType's default constructor
Faculty::Faculty()
	: Person() {
	setId(-1); // lab 6 facultyId use Person::id
	departmentName = "NoDepart";
}
//Parameterized constructor
//Uses a PersonType object to easily initialize the inherited members by
//calling the base class copy constructor
Faculty::Faculty(int id, string d, const Person& personData)
	: Person(personData) {
	setId(id);
	departmentName = d;
}

void Faculty::print() const {
	cout << left << setw(3) << id << setw(10) << firstName << setw(10) << lastName << setw(15) << departmentName \
		<< setw(30) << address << setw(10) << city << setw(10) << state << setw(6) << zip << setw(15) << email \
		<< setw(15) << phone << endl;

}

bool Faculty::operator==(const Faculty& otherF) const{
	return getId() == otherF.getId();
}
bool Faculty::operator!=(const Faculty& otherF) const{
	return !(*this == otherF);
}

bool Faculty::operator>(const Faculty& otherF) const{
	return getId() > otherF.getId();
}
bool Faculty::operator<(const Faculty& otherF) const{
	return !(*this > otherF || *this == otherF);
}
bool Faculty::operator>=(const Faculty& otherF) const{
	return !(*this < otherF);
}
bool Faculty::operator<=(const Faculty& otherF) const{
	return !(*this > otherF);
}
