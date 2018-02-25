// Include the SqlToken.h header file
#include"SqlToken.h"
#include <cstring>

//When the num of tokens is 0 initialize value with an empty string
SqlToken::SqlToken():TokenType(0)
{
  strcpy(TokenValue,"");
}

SqlToken::SqlToken(int tokentype, char value[])
{
    TokenType = tokentype;
    strcpy(TokenValue,value);
}
