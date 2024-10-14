#pragma once
#include <string>
#include "dateTime.h"
using namespace std;

class Assignment {
    friend ostream& operator<<(ostream&, Assignment&);
    friend istream& operator>>(istream& in, Assignment& a);    

public:
    Assignment();
    void setName(string n) { name = n; };
    void setAvailableDate(string a);
    void setDueDate(string d);
    void setPossiblePoint(int p) { possiblePoints = p; };
    void setPoint(int p) { points = p; };
    void setStatus(int s) { status = s; };

    string getName() { return name; };
    DateTime getAvailableDate() { return availableDate; };
    DateTime getDueDate() { return dueDate; };
    int getPossiblePoint() { return possiblePoints; };
    int getPoint() { return points; };
    int isCompleted() { return status == 1; };

    string toCSV();

    Assignment& operator=(const Assignment& other);
    bool operator >= (const Assignment& a) const;
    bool operator == (const Assignment& a) const;

    static void printHeader();

private:

    string name;
    DateTime availableDate;
    DateTime dueDate;
    int possiblePoints;
    int points;
    int status;  // 1=Yes; 0=No

    string getStatus() {
        return isCompleted() ? "DONE" : "Pending";
    };
};
