//
// Created by Alina on 30.04.2022.
//

#ifndef PROGRAM_LANGUAGE_PARSER_H
#define PROGRAM_LANGUAGE_PARSER_H
#include "Parser.h"
#include "Token.h"
#include "Expr.h"
#include "ExpAs.h"
#include "Node.h"
#include <optional>
#include <string>
#include <list>

class Parser {
    void checkTokensInBrc(std::vector<Token>& tokens);
    void checkInBrk(std::vector<Token>& tokens);
    bool checkTokensAs(std::vector<Token>& tokensLine);
    bool checkTokensKey(std::vector<Token>& tokensLine);
    std::vector<Token>::iterator actualToken;
    std::vector<Token>::iterator lastToken;
    std::list<Expr*>::iterator firstToken;
    std::list<Expr*>::iterator endToken;
    bool expID();
    bool expINT();
    bool expOP();
    bool expOPER();
    bool expLbr();
    bool expRbr();
    bool expLbrc();
    bool expRbrc();
    bool expKey();
    bool val();
    bool expr();
    bool infinity();
    bool expSTR();
    Node* root;


public:
    Parser(Node* node);
    void addTokens(std::vector<Token> &tokens);
    void parseAs(std::vector<Token>& tokens);
    bool IsOperator(ExprType type);
    int Priority(ExprType type);
    std::list<Expr*> ReversePolishNotation(std::list <Expr *>);
    Node* addNodeExpr(const std::list<Expr *>&);

    void parseKEY(std::vector<Token> &tokens);

    void parseIF(std::vector<Token> &tokens);

    Node *getNode();

    void parseWHILE(std::vector<Token> &tokens);

    void parsePRINT(std::vector<Token> &tokens);
};

#endif //PROGRAM_LANGUAGE_PARSER_H
