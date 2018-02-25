//InputFileParser.cpp reads the file line by line and reads the completefile to the function which
//called the InputFileParser.cpp
#include <fstream>
#include <cstring>
#include "InputFileParser.h"

char* InputFileParser::GetFile(char* inputfile)
{
  //Ask for inputfile
  ifstream input_object(inputfile);
  if(!input_object)
  {
      cout<<"The input File " << inputfile << "is not accessible"<<endl;
      return NULL;
  }
  char sentencelength[255];               //holds a single statement line
  char* completefile = new char[499999];  //holds a set of statements
  //While the length of the input line is 255 or less append the line to the input file
  while(input_object.getline(sentencelength,255))
  {
      strcat(completefile,sentencelength);
      strcat(completefile,"\n");
  }
  return completefile;
}

string InputFileParser::GetFileString(char* inputfile)
{
  ifstream input_object(inputfile);
  if(!input_object)
  {
      cout<<"The string File" << inputfile <<"is not accessible "<<endl;
      string s = " ";
      return s;
  }

  char sentencelength[255];       //holds a single statement line
  string completefileString= " "; //holds a set of statements
  //While the length of the input line is
  //255 or less append the line to the input file
  while(input_object.getline(sentencelength,255))
  {
      completefileString.append(sentencelength);
      completefileString.append("\n");
  }
  return completefileString;
}
