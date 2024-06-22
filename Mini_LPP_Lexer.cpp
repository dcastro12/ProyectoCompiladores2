#include <fstream>
#include "Mini_LPP_Lexer.hpp"
#include "Mini_LPP_LexerImpl.hpp"
#include <iostream>
#include <string>
#include <algorithm> 

Mini_LPP_Lexer::Mini_LPP_Lexer(std::istream& _in)
  : in(_in)
{
    yylex_init_extra(&in, &yyscanner);
}

Mini_LPP_Lexer::~Mini_LPP_Lexer()
{
    yylex_destroy(yyscanner);
}

std::string Mini_LPP_Lexer::text() const
{
    return std::string(yyget_text(yyscanner));
}

const int Mini_LPP_Lexer::line() const
{
    return yyget_lineno(yyscanner);
}

