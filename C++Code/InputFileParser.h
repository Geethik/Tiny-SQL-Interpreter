//InputFileParser.cpp reads the user input
#ifndef _INPUTFILEPARSER_H
#define _INPUTFILEPARSER_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class InputFileParser
{
private:
    char inputfile[100];
public:
    char* GetFile(char* inputfile);
    string GetFileString(char* inputfile);
};
#endif
