// Programs analyses the input file by returned bythe inputfileParser to tokenize the input
//  LexicalAnalyzer.cpp
//
#include <cstring>
#include"LexicalAnalyzer.h"
MyKeyWords LexicalAnalyzer::keyword;

//Creating an instance of the Lexer class
LexicalAnalyzer::LexicalAnalyzer(){
    cout<<"Initialization of Lexical Analysis of the input"<<endl;
}

//Initializing the Lexical analyzer with the input text to parse
LexicalAnalyzer::LexicalAnalyzer(const char* input_text){

    strcpy(input_parse,input_text);
    curr_char = input_parse;
    prev_char = curr_char;
}


//Getting the next character for the lexical analyzer to parse
char LexicalAnalyzer::GetNextCharacter(){
    return *curr_char;
}

//Get the next token
SqlToken LexicalAnalyzer::GetNextToken(){
    prev_char = curr_char;
    SqlToken token;

    while(*curr_char == '\n' || *curr_char == '\t' || *curr_char == ' ')
    {
        *curr_char++;
    }

    if(*curr_char == ',')
    {
		char *var_temp = (char*)",";
        token = SqlToken(COMMA, var_temp);
        curr_char++;
    }
    else if(*curr_char == '"')
    {

        int index = 0;
        curr_char++;
        while(*curr_char != '"')
        { // string with the qoutes like literal in "Literal"
            token.TokenValue[index] = *curr_char;
            index++;
            curr_char++;
        }
        token.TokenValue[index] = '\0'; //assign a null string to tokenvalue at index 0
        curr_char++;
        if(*curr_char != ' ' && *curr_char != '\n' && *curr_char!=',' && *curr_char!= ')' && *curr_char!='\0') {
            //Check if there is any character other than above mentioned the throw an error
            //if "Literal1 & Literal2 " pops an Incorrect Syntax error. It should be "Literal1 & Literal2"
            throw string("Incorrect Syntax");
        }
        token.TokenType = LITERAL;
    }
    else if(*curr_char == '/')
    {
		char *var_temp = (char*)"/";
        token = SqlToken(DIVISION, var_temp);
        curr_char++;

    }
    else if(*curr_char == '.')
    {
		char *var_temp = (char*)".";
        token = SqlToken(PERIOD, var_temp);
        curr_char++;

    }
    else if(*curr_char == ')')
    {
		char *var_temp = (char*)")";
        token = SqlToken(ENCLOSINGPAREN, var_temp);
        curr_char++;

    }
    else if(*curr_char == ']')
    {
	    char *var_temp = (char*)"]";
        token = SqlToken(ENCLOSINGSQPAREN, var_temp);
        curr_char++;

    }
    else if(*curr_char == '(')
    {
		char *var_temp = (char*)"(";
        token = SqlToken(OPENINGPAREN,var_temp);
        curr_char++;

    }
    else if(*curr_char == '[')
    {
        char *var_temp = (char*)"[";
		token = SqlToken(OPENINGSQPAREN,var_temp);
        curr_char++;

    }
    else if(*curr_char == '-')
    {
		char *var_temp = (char*)"-";
        token = SqlToken(MINUS,var_temp);
        curr_char++;

    }
    else if(*curr_char == '+')
    {
		char *var_temp = (char*)"+";
        token = SqlToken(ADDITION,var_temp);
        curr_char++;

    }
    else if(*curr_char == ';')
    {
		char *var_temp = (char*)";";
        token = SqlToken(SEMICOLON,var_temp);
        curr_char++;

    }
    else if(*curr_char == '*')
    {
		char *var_temp = (char*)"*";
        token = SqlToken(MULTIPLY,var_temp);
        curr_char++;

    }
    else if(*curr_char == '=' || *curr_char == '>' || *curr_char == '<')
    {
        token.TokenValue[0] = *curr_char;
        token.TokenValue[1] = '\0';
        token.TokenType = COMPOPERATOR;
        curr_char++;
    }
    else if(isalnum(*curr_char))
    {// check if the input is an interger or a string.
        int index =0;
        bool all_digit = true;
        bool not_an_identifier = false;
        if(isdigit(*curr_char))
            not_an_identifier = true; // not a table or a columnname
            while(isalnum(*curr_char))
            {
                if(isalpha(*curr_char)) {
                    all_digit = false; //input is not an integer
                }
                token.TokenValue[index] = *curr_char;
                curr_char++;
                index++;
            }
            token.TokenValue[index] = '\0';
            int type;
            if(all_digit)
            {
                token.TokenType = INTEGER; //mark tokentype as an integer
            }
            else if((type = keyword.KeywordToken(token.TokenValue))!=0) {
                token.TokenType = type;
            }
            else if(type == 0)
            {
                if(!not_an_identifier) {
                    token.TokenType = IDENTIFIER;
                }
                else {
                    token.TokenType = UNDEFINEDTOK;
                    strcat(token.TokenValue,"Error - Invalid Token");
                }
            }
        }
        else if(*curr_char == '\0')
        {
			char *var_temp = (char*)"End of File";
            token = SqlToken(EOF, var_temp);
        }
        else if(*curr_char!= '\n' && *curr_char!=' ')
        {
            token.TokenType = UNDEFINEDTOK;
            token.TokenValue[0] = *curr_char;
            token.TokenValue[1] = '\0';
            strcat(token.TokenValue, "ERROR - Undefined Token");
            curr_char++;
        }

    return token;
}

void LexicalAnalyzer::RestorePreviousToken()
{
    curr_char = prev_char;
}

char* LexicalAnalyzer::getCurrentCharacter() {
    return curr_char;
}

void LexicalAnalyzer::LexerReset(char* reset_character){
    curr_char = reset_character;
    prev_char = curr_char;
}
