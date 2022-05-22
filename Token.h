
#ifndef PROGRAM_LANGUAGE_TOKEN_H
#define PROGRAM_LANGUAGE_TOKEN_H

#include<unordered_set>
#include<string>
#include <regex>

    enum TokenType
    {
        Identifier,
        Int_D,
        Double_D,
        Keyword,
        String,
        Delims,
        Semicolons,
        L_br,
        R_br,
        L_brc,
        R_brc,
        Brack,
        Brc,
        Operator,
        Op
    };

    static const std::unordered_set<std::string> operators = { "+", "-", "*", "/", ",", "=" , "^",  "<", ">"};
    static const std::unordered_set<char> whitespace = { '\n', '\r', '\t', ' ' };
    static const std::unordered_set<char> delims = { '(', ')', ';' };
    static const std::unordered_set<char> semicolon = {';'};
    static const std::unordered_set<std::string> brack = {"{", "}"};
    static const std::unordered_set<std::string> brc = {"(", ")"};
    static const std::unordered_set<std::string> ops = {"==",  "&&", "||", "!=",  "<=", ">="};


    class Token
    {
    public:
        std::string tokenValue;
        TokenType tokenType;

        Token(const std::string& tokenValue_, TokenType tokenType_);
        Token(const Token& token);

        TokenType getType();
        std::string getValue();
    };

#endif
