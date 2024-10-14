#pragma once
#include "person.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Faculty: public Person{
public:
	Faculty();
	Faculty(int id, string d, const Person&);
	~Faculty() {};

	//Mutator functions
	void setDepartment(string d) { departmentName = d;};

	//Accesor functions	
	string getDepartment() const { return departmentName;};

	void print() const;

	//Overloaded operators
	bool operator==(const Faculty&) const;
	bool operator!=(const Faculty&) const;
	bool operator>(const Faculty&) const;
	bool operator<(const Faculty&) const;
	bool operator>=(const Faculty&) const;
	bool operator<=(const Faculty&) const;

private:
	 // int facultyId; // lab 5 - Person::id
	 string departmentName; 
};

