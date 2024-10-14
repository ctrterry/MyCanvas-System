#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "dateTime.h"

using namespace std;

class Announcement{
    friend ostream& operator<<(ostream& os, Announcement& ann){
        string seperator = "\n";
        os << ann.getTitle() << seperator
           << ann.getStringDateType() << seperator
        << ann.getText() << seperator ;
        return os;
    };
    friend istream& operator>>(istream& in, Announcement& a);
    public:
        Announcement();

        void setTitle(string name) { title = name; };
        void setDateType(string dt) { postDate.setDate(dt); };
        void setText(string txt) { text = txt; };
        void setDate(string inputDate) {Date = inputDate;};
        string getDate(){return Date;};

     string getTitle() const { return title; };
        DateType getDateType() const {
            return postDate;
        };
    
    string getStringDateType() const {
        return postDate.toString();
    }
    string getText(){
        return text;
    }
        void print() const;

        //Overloaded operators
        bool operator>=(const Announcement&) const;
        bool operator<=(const Announcement&) const;
        bool operator<(const Announcement&) const;
        bool operator>(const Announcement&) const;
        bool operator==(const Announcement&) const;
        bool operator!=(const Announcement&) const;        

    private:
        string title;
        DateType postDate;
        string text;
        string Date;
};
