#include "Token.h"


Token::Token(const std::string& tokenValue_, TokenType tokenType_)
{
    this->tokenValue=tokenValue_;
    this->tokenType=tokenType_;
}

Token::Token(const Token& token)
{
    this->tokenValue=token.tokenValue;
    this->tokenType=token.tokenType;
}

TokenType Token::getType() {
    return tokenType;
}

std::string Token::getValue() {
    return tokenValue;
}