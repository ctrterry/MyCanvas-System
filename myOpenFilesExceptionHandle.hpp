//
//  myOpenFilesExceptionHandle.hpp
//  Lab6Fixed
//
//  Created by Terry Chen on 11/26/22.
//

#ifndef myOpenFilesExceptionHandle_hpp
#define myOpenFilesExceptionHandle_hpp
#include <string>
using namespace std;
class myOpenFilesExceptionHandle
{
public:
    myOpenFilesExceptionHandle(){
        message = "Open Files is Incorrect . . . ";
    };
    myOpenFilesExceptionHandle(string str){
        message = str;
    };
    string what(){
        return message;
    }
private:
    string message;
};


#endif /* myOpenFilesExceptionHandle_hpp */
