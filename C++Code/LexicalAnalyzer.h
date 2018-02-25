//Programs analyses the input file by returned bythe inputfileparser to tokenize the input
//  LexicalAnalyzer.h
//

#ifndef LexicalAnalyzer_h
#define LexicalAnalyzer_h
#include<fstream>
#include<iostream>
#include"SqlToken.h"
#include"MyKeyWords.h"
using namespace std;

class LexicalAnalyzer
{
    private:
    //LexicalAnalyzer can parse a maximum of 200 characters.
        char input_parse[499999];
        //Pointer to point to my current and previous token
        char* curr_char;
        char* prev_char;
        //Static objects can be called without instantiating an object of that class.
        static MyKeyWords keyword;

    public:
        //Constructor
        LexicalAnalyzer();
        LexicalAnalyzer(const char* input_text);

        //calling the method GetNextToken() of the type class SqlToken
        SqlToken GetNextToken();

        //calling the method GetNexTCharacter() which returns a token of character type
        char GetNextCharacter();

        //call RestorePreviousToken() to access the previous token
        void RestorePreviousToken();

        //these 2 used only for condition Insert into table select * from table
        //basically go back once you have gone forward while parsing a piece of text
        char* getCurrentCharacter();//returns the current position in parsing text
        void LexerReset(char* reset_character); //resets the parsing pointer to the point specified

};
#endif /* LexicalAnalyzer_h */
