#include "Mini_LPP_Parser.hpp"


int Mini_LPP_Parser::parse()
{

    return yyparse(*this);
}
