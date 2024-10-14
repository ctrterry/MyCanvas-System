//
//  myHashTable.hpp
//  Lab6Fixed
//
//  Created by Terry Chen on 11/25/22.
//

#ifndef myHashTable_hpp
#define myHashTable_hpp
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;

class comparied;
class myHashTable
{
public:
    myHashTable() { key = 0; title = " "; };
    ~myHashTable() { };
    void setkey(int key){ this->key = key;};
    void setTitle(string title){ this->title = title;};
    int getkey() const { return this->key;};
    string getTitle() const { return this->title;};
    
    //Overloaded operators
    /*
    myHashTable& operator=(const  myHashTable& other){
        this->setkey(other.getkey());
        this->setTitle(other.getTitle());
        return *this;
    }
    bool operator>=(const myHashTable&) const;
    bool operator==(const myHashTable& other) const{
        return (this->title == other.title);
    }
     */
private:
    int key;
    string title;
    friend class comparied;
};

class myHashTable;
class comparied
{
public:
    bool operator==(const comparied& other) const{
        return ( this->_hash.title == other._hash.title);
    }
    
    bool relationalOperation(string s1, string s2){
        return (s1 == s2);
    };
    
    void pushData(int key, string title){
        myHashTable hash;
        hash.setkey(key);
        hash.setTitle(title);
        keys.push_back(hash);
    };
    bool checkKeyAuthenticate(string title){
        bool valid = false;
        for(int i=0; i< (int) keys.size(); i++){
            if(_hash.getkey() == keys.at(i).getkey() &&
               _hash.getTitle() == keys.at(i).getTitle()){
                valid = true;
                break;
            }
        }
        return valid;
    };
    
    int getKey(string title){
        _hash.setTitle(title);
        for(int i=0; i< (int) keys.size(); i++){
            
            cout << title << " | " << keys.at(i).getTitle() << " | " <<
            keys.at(i).getkey() <<  endl;
            if( relationalOperation(title, keys.at(i).getTitle()) ){
                return keys.at(i).getkey();
            }
        }
        return -1;
    }
private:
    vector<myHashTable> keys;
    myHashTable _hash;
    friend class myHashTable;
};

#endif /* myHashTable_hpp */
