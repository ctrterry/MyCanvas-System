#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include <fstream>
#include <ctime>
#include <iostream>
#include "utils.h"

using namespace std;
//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
	time_t t = std::time(0);    // get time now
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}

bool openFile(fstream& inFile, string fileName) {
	//inFile.open(fileName, ios::in | ios::out | ios::app);
	inFile.open(fileName);
    return inFile.is_open();
}

string getUserFileInput(){
    string fileName = "";
    cout << "Input Your New Filed Name: ";
    cin >> fileName;
    return fileName;
}

bool Is_Number(string str){
    bool valid = false ;
    for(int i =0 ;i < str.length();i++){
        if(isdigit(str[i]) == false){
            break;
        }
        else{
            valid = true;
        }
    }
    return valid;
}
string macFileNamePrefixed()
{
    string prefixed = "/Users/terrychen/Desktop/xCodeProjectFolder/Solution/Solution/Lab6Fixed/Lab6Fixed/";
    return prefixed;
}

void printOhloneHeader(){
        
        cout << R"(
     ##     ## ##    ##     ######        ###       ##    ##    ##     ##       ###        ######
     ###   ###  ##  ##     ##    ##      ## ##      ###   ##    ##     ##      ## ##      ##    ##
     #### ####   ####      ##           ##   ##     ####  ##    ##     ##     ##   ##     ##
     ## ### ##    ##       ##          ##     ##    ## ## ##    ##     ##    ##     ##     ######
     ##     ##    ##       ##          #########    ##  ####     ##   ##     #########          ##
     ##     ##    ##       ##    ##    ##     ##    ##   ###      ## ##      ##     ##    ##    ##
     ##     ##    ##        ######     ##     ##    ##    ##       ###       ##     ##     ######

    )";
}

void printTeamProject(){
    cout << R"(
$$$$$$$$\                                      $$$$$$$\                         $$$$$\                       $$\
\__$$  __|                                     $$  __$$\                        \__$$ |                      $$ |
   $$ | $$$$$$\   $$$$$$\  $$$$$$\$$$$\        $$ |  $$ | $$$$$$\   $$$$$$\        $$ | $$$$$$\   $$$$$$$\ $$$$$$\
   $$ |$$  __$$\  \____$$\ $$  _$$  _$$\       $$$$$$$  |$$  __$$\ $$  __$$\       $$ |$$  __$$\ $$  _____|\_$$  _|
   $$ |$$$$$$$$ | $$$$$$$ |$$ / $$ / $$ |      $$  ____/ $$ |  \__|$$ /  $$ |$$\   $$ |$$$$$$$$ |$$ /        $$ |
   $$ |$$   ____|$$  __$$ |$$ | $$ | $$ |      $$ |      $$ |      $$ |  $$ |$$ |  $$ |$$   ____|$$ |        $$ |$$\
   $$ |\$$$$$$$\ \$$$$$$$ |$$ | $$ | $$ |      $$ |      $$ |      \$$$$$$  |\$$$$$$  |\$$$$$$$\ \$$$$$$$\   \$$$$  |
   \__| \_______| \_______|\__| \__| \__|      \__|      \__|       \______/  \______/  \_______| \_______|   \____/

)";
}


void printMy(){
    cout << R"(
                                              $$\      $$\
                                              $$$\    $$$ |
                                              $$$$\  $$$$ |$$\   $$\
                                              $$\$$\$$ $$ |$$ |  $$ |
                                              $$ \$$$  $$ |$$ |  $$ |
                                              $$ |\$  /$$ |$$ |  $$ |
                                              $$ | \_/ $$ |\$$$$$$$ |
                                              \__|     \__| \____$$ |
                                                           $$\   $$ |
                                                           \$$$$$$  |
                                                            \______/

)";
    cout << endl;
}

void printMyCanvas(){
    printMy();
    cout << R"(
 .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |     ______   | || |      __      | || | ____  _____  | || | ____   ____  | || |      __      | || |    _______   | |
| |   .' ___  |  | || |     /  \     | || ||_   \|_   _| | || ||_  _| |_  _| | || |     /  \     | || |   /  ___  |  | |
| |  / .'   \_|  | || |    / /\ \    | || |  |   \ | |   | || |  \ \   / /   | || |    / /\ \    | || |  |  (__ \_|  | |
| |  | |         | || |   / ____ \   | || |  | |\ \| |   | || |   \ \ / /    | || |   / ____ \   | || |   '.___`-.   | |
| |  \ `.___.'\  | || | _/ /    \ \_ | || | _| |_\   |_  | || |    \ ' /     | || | _/ /    \ \_ | || |  |`\____) |  | |
| |   `._____.'  | || ||____|  |____|| || ||_____|\____| | || |     \_/      | || ||____|  |____|| || |  |_______.'  | |
| |              | || |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'
)";
}

void printCourseHeader(){
    cout << endl << endl;
    cout << left << setw(8) << "Term" << setw(5) << "Year" << setw(12) << "Start Date"<< setw(12)
        << "End Date" << setw(32) << "Name" << setw(10) << "Section"
        << setw(10) << "Id" << setw(8) << "Meet Day" << setw(10) << "Location"
        << setw(10) << "MeetInfo" << setw(15) << "Last Name"
        << setw(5) << "Units" << endl;
}
