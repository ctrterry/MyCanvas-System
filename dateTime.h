#pragma once
#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include <string>
using namespace std;

const string FORMAT_SEPARATOR = "/";

class DateType {
public:
	DateType(int m = 0, int d = 0, int y = 0);
	~DateType() {};

	//Mutator functions
	void setMonth(int m) { month = m; };
	void setDay(int d) { day = d; };
	void setYear(int y) { year = y; };

	//string format mm/dd/yyyy
	void setDate(string);

	//Accessor functions
	int getMonth() const { return month; };
	int getDay() const { return day; };
	int getYear() const { return year; };
    string getCombiteDate(){
        return to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
    }
    
    
	DateType& getDate();

	string toString() const; //mm-dd-yyyy
	bool isEmpty() const {
		return month == 0 && day == 0 && year == 0;
	};

	//Overloaded operators - add lab5
	bool operator>(const DateType&) const;
	bool operator<(const DateType&) const;
	bool operator>=(const DateType&) const;
	bool operator<=(const DateType&) const;
	bool operator==(const DateType&) const;
	bool operator!=(const DateType&) const;	

	void copy(const DateType& otherObject);

protected:
	int month;
	int day;
	int year;
};

class DateTime : public DateType {
public:
	DateTime(int h = 0, int mi = 0, int s = 0, int mo = 0, int d = 0, int y = 0);
	~DateTime() {};

	//Mutator functions
	void setHour(int h) { hr = h; };
	void setMinute(int m) { min = m; };
	void setSecond(int s) { sec = s; };

	//Sets the time by passing in a string in mm/dd/yyyy hr:min:sec
	void setDateTime(string);

	//Accessor functions
	int getHour() const { return hr; };
	int getMinute() const { return min; };
	int getSecond() const { return sec; };
    string getCombiteTime(){
        return to_string(getHour()) + ":" + to_string(getMinute()) + ":" + to_string(getSecond());
    };

	string toString(); //mm-dd-yyyy hh:mm:ss
	bool isEmpty() const {
		return hr == 0 && min == 0 && sec == 0;
	};

	//Overloaded operators - add lab5
	bool operator>(const DateTime&) const;
	bool operator<(const DateTime&) const;
	bool operator>=(const DateTime&) const;
	bool operator<=(const DateTime&) const;
	bool operator==(const DateTime&) const;
	bool operator!=(const DateTime&) const;

	void copy(const DateTime& otherObject);  // Lab5

private:
	int hr;  //variable to store the hours
	int min; //variable to store the minutes
	int sec; //variable to store the seconds
};
