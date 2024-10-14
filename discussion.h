#pragma once
#include <string>
#include "student.h"
#include "dateTime.h"
using namespace std;

class Discussion {
    // TODO
    friend ostream& operator<<(ostream&, Discussion& );
    friend istream& operator>>(istream& in, Discussion& d);

public:
    Discussion();

    string getText() const;
    void setStudent(Student s) {
        student.copy(s);
    };

    Student getStudent() const {
        return student;
    };

    void setDateTime(string dt) {
        postDate.setDateTime(dt);
    };
    void setDateTime(DateTime dt) {
        postDate.copy(dt);
    };

    DateTime getDateTime() const {
        return postDate;
    };
    void setText(string t) {
        text = t;
    }

    string getName() const;

    void print() const;

    Discussion& operator=(const Discussion& otherObject); // Lab 5

    //Overloaded operators
    bool operator>=(const Discussion&) const;
    bool operator<=(const Discussion&) const;
    bool operator<(const Discussion&) const;
    bool operator>(const Discussion&) const;
    bool operator==(const Discussion&) const;
    bool operator!=(const Discussion&) const;
    
private:
    Student student;    
    DateTime postDate;
    string text;

};
