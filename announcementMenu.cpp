#include <iostream>
#include <string>
#include <sstream>
#include "menu.h"
#include "announcement.h"
#include "announcementMenu.h"
#include "linkedStack.h"
#include "utils.h"
using namespace std;

AnnouncementMenu::AnnouncementMenu()
    : Menu("Announcements Menu") {
    addOption("1) List");
    addOption("2) View");
    addOption("3) Add");
    addOption("4) Edit");
    addOption("5) Delete");
    addOption("x) Exit");

    pSelected = nullptr;
    list = new AnnouncementListType();
    init();
};

AnnouncementMenu::~AnnouncementMenu() {
    for(map<int, Announcement*>::iterator i = mapAnnouncement.begin();
        i != mapAnnouncement.end(); ++i){
        delete i->second;
    }
    delete list;
    inFile.close();
}

void AnnouncementMenu::init() {
    openFile(inFile, ANNOUNCEMENT_DATA);
    string title;
    string postDate;
    string text;

    HashTable hash(100);

    while(! inFile.eof() ){
        getline(inFile, title);
        getline(inFile, postDate);
       // cout << "postDate: " << postDate << endl;
        getline(inFile, text);
        //cout << "text:  " << text << endl;
        
        cout << endl;
        
        Announcement* p = new Announcement();
        int key = hash_code(title);
        _keys.push_back(key);
        _titles.push_back(title);
        mapAnnouncement.insert(pair<int,Announcement*>(key ,p));
        p->setTitle(title);
       // cout << postDate << endl;
        p->setDateType(postDate);
        p->setText(text);
        list->push(*p);
        
    }
    inFile.clear();
}

void AnnouncementMenu::doList() {
    cout << "***** Announcement *****" << endl;    
    //Make a copy of the stack to go through each element
    LinkedStackType<Announcement> copy = *list;
    while (!copy.isEmptyStack()) {
        Announcement a = copy.top();
        a.print();
        copy.pop(); // advance to next
    }
}

void AnnouncementMenu::getKeys(){
    for(int i=0; i< _keys.size();i++){
        cout << "Title: " << _titles[i] << "Keys: " << _keys[i] << endl;
    }
}

void AnnouncementMenu::doView() {
    cout << "***** View Announcement *****" << endl;
    // TODO...
    getKeys();
    cout << "Please Enter Announcement's Key: ";
    string key_annoc = "";
    cin.ignore();
    getline(cin,key_annoc);
    int key = stoi(key_annoc);

    Announcement * ptr = mapAnnouncement[key];
   
    if(ptr != nullptr){
        ptr->print();
    }
    else{
        cout << "Your Students ID Number Is Not Exist" << endl;
    }

}

void AnnouncementMenu::doAdd() {
    cout << "***** Add Announcement *****" << endl;
     // TODO...
     string title;
     string postDate;
     string text;

     cout << "Enter You Title: ";
     cin.ignore();
     getline(cin,title);
     cout << "Enter Your Post Date: ";
     cin >> postDate;
     cout << "Enter you text: ";
     cin.ignore();
     getline(cin, text);
     
     Announcement* p = new Announcement();
     int key = hash_code(title);
     _keys.push_back(key);
     _titles.push_back(title);
     mapAnnouncement.insert(pair<int,Announcement*>(key ,p));
     p->setTitle(title);
     p->setDateType(postDate);
     p->setText(text);
     list->push(*p);

}

void AnnouncementMenu::doEdit() {
    cout << "***** Edit Announcement *****" << endl;
        // TODO...
        getKeys();
        cout << "Whcih Element Keys would you want to Edit? ";
        int elementKey;
        cin >> elementKey;
        Announcement * ptr = mapAnnouncement[elementKey];
       
        if(ptr == nullptr){
            cout << "Your Students ID Number Is Not Exist" << endl;
        }
        else{
            string title;
            string postDate;
            string text;
            cout << "Edit You New Title ( " << ptr->getTitle() << "): " ;
            cin.ignore();
            getline(cin,title);
            cout << "Edit You New Post Date ( " << ptr->getStringDateType() << "): " ;
            cin >> postDate;
            cout << "Edit You New Text ( " << ptr->getText() << "): " ;
            cin.ignore();
            getline(cin, text);
            
            Announcement* p = new Announcement();
            int key = hash_code(title);
            _keys.push_back(key);
            _titles.push_back(title);
            mapAnnouncement.insert(pair<int,Announcement*>(key ,p));
            p->setTitle(title);
            p->setDateType(postDate);
            p->setText(text);
            list->push(*p);
        }


        
}

void AnnouncementMenu::doDelete() {
    cout << "***** Delete Announcement *****" << endl;
    // TODO...
    getKeys();
    cout << "Please Enter Your Element Key: ";
    int key;
    cin >> key;
    Announcement * ptr = mapAnnouncement[key];
    if(ptr == nullptr){
        cout << "Invalid Students ID Numbers" << endl;
    }
    else{
        map<int, Announcement*>::iterator it;
        it = mapAnnouncement.find(key);
        mapAnnouncement.erase(it);
    }
}

/**
* Save to file
*/
void AnnouncementMenu::doSave() {
    fstream file;
    cout << "Saving Announcement Data into a New file\n";
     cout << "Privide a New Files Name:  ";
     char fileName[100];
        cin>>fileName;
        cin.ignore();
        file.open(fileName,ios::out|ios::in|ios::app);
        if (file.is_open()) {
            LinkedStackType<Announcement> copy = *list;
            while (!copy.isEmptyStack()) {
                Announcement a = copy.top();
               
                file << a << endl;
                /*
                file << a.getTitle() << "\n" << a.getStringDateType() << "\n"
                << a.getText() << endl;
                 */
                copy.pop(); // advance to next
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
