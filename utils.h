#pragma once
#include <fstream>
#include <string>

using namespace std;

bool openFile(fstream& inFile, string fileName);

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec);

string getUserFileInput();

bool Is_Number(string str);

string macFileNamePrefixed();

void printOhloneHeader();

void printTeamProject();

void printMyCanvas();

void printMy();

void printCourseHeader();
