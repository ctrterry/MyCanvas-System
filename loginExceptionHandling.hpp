//
//  loginExceptionHandling.hpp
//  Lab6Fixed
//
//  Created by Terry Chen on 11/26/22.
//

#ifndef loginExceptionHandling_hpp
#define loginExceptionHandling_hpp

#include <string>
using namespace std;
class myLoginExceptionHandling
{
public:
    myLoginExceptionHandling(){
        message = "Login Error ...";
    };
    myLoginExceptionHandling(string str){
        message = str;
    };
    
    string what(){
        return message;
    }
private:
    string message;
};


#endif /* loginExceptionHandling_hpp */
