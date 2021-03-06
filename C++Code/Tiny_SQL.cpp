#include <iostream>
#include <fstream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <time.h>
#include <math.h>

#include "InputFileParser.h"
#include "GlobalFile.h" // defines the memory and disk specifications
#include "Analyzer.h"   //my parsing functionality
 

using namespace std;
InputFileParser filecontroller;
Analyzer analyzer;

int main(){

    char* myinput = NULL;
    char sentence[300];
    string inputcommand;
    string outputoption;
    string query_filename;
    char* cstr_query_filename;
    char* cstr_outputoption;
    int out_option;

    ofstream qout_file;
    qout_file.open("query_output", ofstream::out);

    time_t start_time;
    time_t end_time;
    double seconds;
    bool valid_option=false;
    for(;;) // keep running infinitely until you type "exit"
    {
        clock_t start_time = clock();
        // cout<<"\nSelected Command:>";

        cout << "********************************************" << endl;
        cout<<"(1) Input SQL Queries from a File" << endl;
        cout<<"(2) Input SQL Query from Command Prompt" << endl;
        cout<<"(3) Exit" << endl;
        cout<<">> Please Enter an Option (Number): ";
        cin>>inputcommand;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(inputcommand == "1")
        {
            cout << ">> Please Enter the SQL Query File Name: ";
            cin >> query_filename;

            cout << "(1) Print Output to Console" << endl;
            cout << "(2) Print Output to File (query_out)" << endl;
            cout << ">> Please Enter an Option (Number): ";
            cin >> outputoption;

            cstr_outputoption = new char[outputoption.length() + 1];
            strcpy(cstr_outputoption, outputoption.c_str());
            out_option = atoi(cstr_outputoption);

            cstr_query_filename = new char[query_filename.length() + 1];
            strcpy(cstr_query_filename, query_filename.c_str());
            myinput = filecontroller.GetFile(cstr_query_filename);

            if(out_option == 2) {
                qout_file << "Output of SQL Query File: " << query_filename << endl;
                qout_file << "*******************************************" << endl;
            }

            if(myinput == NULL)
            {
                cout<<">> Press any key to Exit";
                //output the key pressed
                getchar();
                exit(1);
            }
            valid_option = true;
            if(out_option == 1) {
                cout << "***********************************************" << endl;
            }
            else if(out_option == 2) {
                qout_file << "*******************************************" << endl;
            }
            else {
                valid_option = false;
            }
            // cout<<"Inputs by the user: "<<endl<<myinput<<endl;
        }
        else if(inputcommand == "2")
        {

            cout << ">> Please Enter the SQL statement: ";
            cin.getline(sentence,255); // get the SQL input from the user .

            cout << "(1) Print Output to Console" << endl;
            cout << "(2) Print Output to File (query_out)" << endl;
            cout << ">> Please Enter an Option (Number): ";
            cin >> outputoption;

            cstr_outputoption = new char[outputoption.length() + 1];
            strcpy(cstr_outputoption, outputoption.c_str());
            out_option = atoi(cstr_outputoption);

            myinput = sentence; // store the input in myinput.
            valid_option = true;
            if(out_option == 1) {
                cout << "**********************************************" << endl;
            }
            else if(out_option == 2) {
                qout_file << "*********************************************" << endl;
            }
            else {
                valid_option = false;
            }
            // cout<<"Inputs by the user: "<<endl<<myinput<<endl;
        }
        else if(inputcommand == "3")
        {
	       valid_option = true;
            exit(EXIT_SUCCESS);
        }
        else
        {
            valid_option = false;
            cout<<"Please Enter a valid choice" << endl;
            // exit(1);
        }

        if(valid_option) {
            try
            {
                analyzer = Analyzer(myinput);
                analyzer.AnalyzeInput(qout_file, out_option);
                analyzer.RemoveVariable(); //clear all global variables
            }
            catch(string error)
            {
                cout<<"An Error has been encountered!"<<error<<endl;
                analyzer.RemoveVariable(); //clear all global variables
            }

            catch(...)
            {
                cout<<"Unhandled Error has been encountered"<<endl;
                analyzer.RemoveVariable(); //clear all global variables
            }
            end_time = clock() - start_time;
            if(out_option == 1) {
                cout << "Time Taken to compute the complete input in seconds: ";
                cout << ((float)end_time)/(CLOCKS_PER_SEC)<<endl;
            }
            else if(out_option == 2) {
                qout_file << "Time Taken to compute the complete input in seconds: ";
                qout_file << ((float)end_time)/(CLOCKS_PER_SEC)<<endl;
            }
            else {}
        }
    }

    qout_file.close();

    getchar();

}
