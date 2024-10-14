//
//  myIntergerExceptionHandle.hpp
//  Lab6Fixed
//
//  Created by Terry Chen on 11/26/22.
//

#ifndef myIntergerExceptionHandle_hpp
#define myIntergerExceptionHandle_hpp
#include <string>
using namespace std;
class myIntergerExceptionHandle
{
public:
    myIntergerExceptionHandle(){
        message = "Error for stoi function convert...";
    };
    myIntergerExceptionHandle(string str){
        message = str;
    };
    string what(){
        return message;
    }
private:
    string message;
};

#endif /* myIntergerExceptionHandle_hpp */
