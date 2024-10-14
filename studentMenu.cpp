#include <sstream>
#include "menu.h"
#include "studentMenu.h"
#include "linkedQueue.h"
#include "utils.h"
#include <map>
#include "myOpenFilesExceptionHandle.hpp"
#include "myIntergerExceptionHandle.hpp"
StudentMenu::StudentMenu()
    : Menu("Course Menu") {
    addOption("1) Student list");   // Lab 5 - sortBy any field in class Student and Person
    addOption("2) View student details");
    addOption("3) Add a student");
    addOption("4) Edit a student");
    addOption("5) Delete a student");
    addOption("x) Exit");

    list = new LinkedQueueType<Student>();
    init();    
};

StudentMenu::~StudentMenu() {
    map<string, Student*>::iterator Iter;
    for(Iter = mapStudent.begin(); Iter != mapStudent.end(); ++Iter){
        delete Iter->second;
    }
    delete list;
    inFile.close();
}

void StudentMenu::init() {
    string fileName = STUDENT_DATA;
    bool valid = false ;
    int attempt = 0;
    while(!valid){
        attempt++;
        if(attempt < 3){
            valid = true;
        }
        try{
            //string fileName = COURSE_DATA;
            // return true or False. for openFile .
            if(openFile(inFile, fileName)){
                break;
            }
            else {
                throw myOpenFilesExceptionHandle();
            }
        }
        catch (myOpenFilesExceptionHandle & op){
            cout << "Student Data: " << op.what() << "Eg, student_data.csv " << endl;
            fileName = getUserFileInput();
        }
    }
    
    string sid;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;

    string studentLine = "";

    while (getline(inFile, studentLine)) {
        stringstream ss(studentLine);
        getline(ss, sid, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, email, ',');

        Student s;
        Student* p = new Student();
        mapStudent.insert(pair<string, Student*>(sid,p));
        
      //  Student* p = &s;
        try {
            if(Is_Number(sid)){
                p->setId(stoi(sid));
            }else{
                throw myIntergerExceptionHandle("Years Error");
            }
            p->setFirstName(firstName);
            p->setLastName(lastName);
            p->setAddress(address);
            p->setCity(city);
            p->setState(state);
            p->setZip(zip);
            p->setPhone(phoneNumber);
            p->setEmail(email);
            list->addQueue(*p);
        }
        catch (myIntergerExceptionHandle &c){
            cout << c.what() << "\nShowing Error Data: " << sid << endl;
            cout << "Input correct Infor: ";
            cin >> sid;
            continue;
        }
    }
    inFile.clear();
}

void StudentMenu::doList() {
    cout << "***** Students *****" << endl;
    //Make a copy of the stack to go through each element
    printStudentHead();
    LinkedQueueType<Student> tmp = *list;
    while (!tmp.isEmptyQueue())  {
        //Student s = tmp.front();
        tmp.front().print();
        tmp.deleteQueue();
    }
}

void StudentMenu::doView() {
    // TODO...
    cout << "***** View  Student Detail By ID *****" << endl;
    cout << "Please Enter Your Personal Students ID Number: ";
    string studentIdNumber;
    cin >> studentIdNumber;
    Student * ptr = mapStudent[studentIdNumber];
    if( ptr != nullptr){
        printStudentHead();
        ptr->print();
    }else{
        cout << "Your Students ID Number Is Not Exist" << endl;
    }
}

void StudentMenu::doAdd() {
    // TODO...
    cout << "***** Add  Student Detail *****" << endl;
    string sid;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;
    cout << "Enter your studnt ID: ";
    cin >> sid;
    cout << "Enter your studnt first Name: ";
    cin >> firstName;
    
    cout << "Enter your studnt last Name: ";
    cin >> lastName;
    
    cout << "Enter your studnt address: ";
    cin.ignore();
    getline(cin, address);
    
    cout << "Enter your studnt city: ";
    cin >> city;
    
    cout << "Enter your studnt state: ";
    cin >> state;
    
    cout << "Enter your studnt zip: ";
    cin >> zip;
    
    cout << "Enter your studnt phone Number: ";
    cin >> phoneNumber;
    
    cout << "Enter your studnt Email: ";
    cin.ignore();
    getline(cin, email);

        Student* p = new Student();
        mapStudent.insert(pair<string, Student*>(sid,p));
        p->setId(stoi(sid));
        p->setFirstName(firstName);
        p->setLastName(lastName);
        p->setAddress(address);
        p->setCity(city);
        p->setState(state);
        p->setZip(zip);
        p->setPhone(phoneNumber);
        p->setEmail(email);
        list->addQueue(*p);
}

void StudentMenu::doEdit() {
    // TODO...
    cout << "***** Edit Your Student Detail *****" << endl;
    cout << "Please Enter Your Personal Students ID Number: ";
    string studentIdNumber;
    cin >> studentIdNumber;
    Student * ptr = mapStudent[studentIdNumber];
    if(ptr == nullptr){
        cout << "Invalid Students ID Numbers" << endl;
    }
    else{
        string sid;
        string firstName;
        string lastName;
        string address;
        string city;
        string state;
        string zip;
        string phoneNumber;
        string email;
        cout << "Edit your New Studnt ID" << "( " << ptr->getId() << " ) :" ;
        cin >> sid;
        cout << "Edit your New Studnt First Name" << "( " << ptr->getFirstName() << " ) :" ;
        cin >> firstName;
        
        cout << "Edit your New Studnt Last Name" << "( " << ptr->getLastName() << " ) :" ;
        cin >> lastName;
        
        cout << "Edit your New Studnt Address" << "( " << ptr->getAddress() << " ) :" ;
        cin.ignore();
        getline(cin, address);
        
        cout << "Edit your New Studnt City" << "( " << ptr->getCity() << " ) :" ;
        cin >> city;
        
        cout << "Edit your New Studnt State" << "( " << ptr->getState() << " ) :" ;
        cin >> state;
        
        cout << "Edit your New Studnt Zip" << "( " << ptr->getZip() << " ) :" ;
        cin >> zip;
        
        cout << "Edit your New Studnt Phone Numbers" << "( " << ptr->getPhone() << " ) :" ;
        cin >> phoneNumber;
        
        cout << "Edit your New Studnt Email" << "( " << ptr->getEmail() << " ) :" ;
        cin.ignore();
        getline(cin, email);
        
        Student* p = new Student();
        
        mapStudent.insert(pair<string, Student*>(sid,p));
        p->setId(stoi(sid));
        p->setFirstName(firstName);
        p->setLastName(lastName);
        p->setAddress(address);
        p->setCity(city);
        p->setState(state);
        p->setZip(zip);
        p->setPhone(phoneNumber);
        p->setEmail(email);
        list->addQueue(*p);
    }
}

void StudentMenu::doDelete() {
    // TODO...
    cout << "***** Delete Your Student Information *****" << endl;
    cout << "Please Enter Your Personal Students ID Number: ";
    string studentIdNumber;
    cin >> studentIdNumber;
    Student * ptr = mapStudent[studentIdNumber];
    if(ptr == nullptr){
        cout << "Invalid Students ID Numbers" << endl;
    }
    else{
        map<string, Student*>::iterator Iter;
       Iter = mapStudent.find(studentIdNumber);
        mapStudent.erase(Iter);
    }
}

/**
* Save to file
*/
void StudentMenu::doSave() {
    fstream file;
    cout << "Saving Student Data into a New file\n";
     cout << "Privide a New Files Name:  ";
     char fileName[100];
        cin>>fileName;
        cin.ignore();
        file.open(fileName,ios::out|ios::in|ios::app);
        if (file.is_open()) {
            LinkedQueueType<Student> tmp = *list;
            while (!tmp.isEmptyQueue())  {
                //Student s = tmp.front();
                file << tmp.front();
                tmp.deleteQueue();
            }
            cout << "Saving... " << macFileNamePrefixed() + fileName << endl;
            file.close();
        }
        else {
            cerr << "Failed to open file : " << macFileNamePrefixed() + fileName
            << " (errno " << errno << ")" << endl;
        }
    cout << "Save!!!" << endl << endl;
    
}
