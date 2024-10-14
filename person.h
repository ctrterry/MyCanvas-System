#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class Person{
public:	
	//Copy constructor
	Person(string fullname); // Lab 5
	Person(const Person& otherObject);
	Person() {};

	virtual ~Person() {};

	//Mutator functions	
	void setId(int id) { this->id = id; };
	
	void setFirstName(string f) { firstName = f;};
	void setMiddleName(string m) { middleName = m; };
	void setLastName(string l) { lastName = l;};
	void setAddress(string a) { address = a;};
	void setCity(string c) { city = c;};
	void setState(string s) { state = s;};
	void setZip(string z) { zip = z;};
	void setPhone(string p) { phone = p;};
	void setEmail(string e) { email = e;};

	//Accessor functions
	int getId() const { return id; };	// lab 5

	string getFirstName() const{ return firstName; };
	string getMiddleName() const { return middleName; }
	string getLastName() const{ return lastName; };
	string getAddress() const{ return address; };
	string getCity() const{ return city; };
	string getState() const{ return state; };
	string getZip() const{ return zip; };
	string getPhone() const{ return phone; };
	string getEmail() const{ return email; };

	void copy(const Person& otherObject);

private:
	void setFullName(string name);

protected:
	int id;
	string firstName;	// first name
	string middleName;	// middle name
	string lastName;	// last name
	string address;		// student address
	string city;		// student's city
	string state;		// student's state
	string zip;			// student zip code
	string phone;		// student's phone number
	string email;
};
