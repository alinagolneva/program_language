
#ifndef PROGRAM_LANGUAGE_LEXER_H
#define PROGRAM_LANGUAGE_LEXER_H

#include <vector>
#include <list>
#include "Token.h"


using LineNo = unsigned int;

    std::vector<Token> Tokenize(std::string filename);

    Token getToken(std::string buffer, LineNo line);



#endif
