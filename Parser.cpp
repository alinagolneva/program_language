#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <list>
#include "Parser.h"
#include "Token.h"
#include "Expr.h"
#include "ExpAs.h"
#include "ExpID.h"
#include "ExpSUM.h"
#include "ExpSUB.h"
#include "ExpDIV.h"
#include "ExpMULT.h"
#include "ExpINT.h"
#include "ExpDOUB.h"
#include "ExpLBR.h"
#include "ExpLBRC.h"
#include "ExpRBR.h"
#include "ExpRBRC.h"
#include "Node.h"
#include "ExpIF.h"
#include "ExpWHILE.h"
#include "ExpCOMPARE.h"
#include "ExpSMALLER.h"
#include "ExpMORE.h"
#include "ExpSMALEQ.h"
#include "ExpMOREEQ.h"
#include "ExpLOGUM.h"
#include "ExpLOGOR.h"
#include "ExpNOTEQ.h"
#include "ExpNOT.h"
#include "ExpSEM.h"
#include "ExpBlock.h"
#include "ExpPRINT.h"


Parser::Parser(Node* node)
{
    this->root=node;
}

void Parser::addTokens(std::vector<Token>& tokens) {
        std::vector<Token> tokenLines;
        bool semicolons = false;
        int brakes = 0;

        for (auto &it: tokens) {

            auto type = it.getType();
            if (type == Semicolons) {
                if (brakes == 0) {
                    semicolons = true;
                    tokenLines.push_back(it);
                } else {
                    tokenLines.push_back(it);
                }
            } else {
                if ((type == Identifier || type == If || type == While || type == Print)) {
                    if (semicolons) {
                        if (!tokenLines.empty()) {
                          checkTokensInBrc(tokenLines);
                          parseIF(tokenLines);
                          parsePRINT(tokenLines);
                          parseWHILE(tokenLines);
                          parseAs(tokenLines);
                          tokenLines.clear();
                        }
                    }
                }

                else if (type == L_brc) {
                    brakes++;
                } else if (type == R_brc) {
                    brakes--;
                }
                semicolons = false;
                tokenLines.push_back(it);
            }
        }

        if (!tokenLines.empty()) {
            checkTokensInBrc(tokenLines);
            parseIF(tokenLines);
            parsePRINT(tokenLines);
            parseWHILE(tokenLines);
            parseAs(tokenLines);
            tokenLines.clear();
        }
    }

    bool Parser::checkTokensAs(std::vector<Token>& tokensLine)
    {
        actualToken=tokensLine.begin();
        lastToken=tokensLine.end();
        if (!expID()) return false;
        ++actualToken;
        if (!expOP()) return false;
        ++actualToken;
        if (expSTR()) {
                ++actualToken;
                if (actualToken->getType()==TokenType::Semicolons)
                {
                    std::cout << "true";
                    return true;
                }
                else {
                    std::cout << "false";
                    return false;
                }
        }
        if (!expr()) {
            std::cout << " check false";
            return false;
        }
        else std::cout << "true as ";
        return true;
    }

    bool Parser::checkTokensKey(std::vector<Token>& tokensLine)
    {
        actualToken=tokensLine.begin();
        lastToken=tokensLine.end();
        if (!expKey()) return false;
        ++actualToken;
         if(infinity())
         {
             actualToken+=2;
             while (actualToken!=lastToken)
             {
                 if (actualToken->getType()!=TokenType::Semicolons)
                 {
                     if (!expID()) return false;
                     ++actualToken;
                     if (!expOP()) return false;
                     ++actualToken;
                     if (!expSTR() && !expr()) return false;
                     std::cout << "OK";
                     return true;
                 }
                 ++actualToken;
             }
         }
        std::cout << "NO!";
        return false;
    }

    bool Parser::infinity() {
        if (expLbr() || expLbrc()) {
            ++actualToken;
            if (expr()) {
                if (expRbr() || expRbrc())
                    return true;
            }
        }
        return false;
    }

    bool Parser::expr()
    {
        if (!val()) {
            return false;
        }
        ++actualToken;
        while (actualToken != lastToken)
        {
            if (expOP() || expOPER())
            {
                ++actualToken;
                if (val())
                    ++actualToken;
                else {
                    return false;
                }
            }
            if (actualToken->getType()==Semicolons || actualToken->getType()==R_brc || actualToken->getType()==R_br)
            {
                return true;
            }
        }
        return false;
    }

    bool Parser::val()
    {
       if (expINT() || expID() || infinity()) return true;
       return false;
    }


    void Parser::checkTokensInBrc(std::vector<Token>& tokensLine) {

        actualToken=tokensLine.begin();
        lastToken=tokensLine.end();

        for (auto x : tokensLine)
        {
            std::cout << x.getValue();
        }
        std::cout << "-----\n";
    }

    bool Parser::expID() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::Identifier) return false;
        else return true;
    }

    bool Parser::expINT() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::Int_D) return false;
        else return true;
    }

    bool Parser::expOPER() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::Op) return false;
        else return true;
    }

    bool Parser::expSTR() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::String) return false;
        else return true;
    }

    bool Parser::expOP() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::Operator) return false;
        else return true;
    }

    bool Parser::expLbr() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::L_br) return false;
        else return true;
    }

    bool Parser::expLbrc() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::L_brc) return false;
        else return true;
    }

    bool Parser::expRbr() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::R_br) return false;
        else return true;
    }

    bool Parser::expRbrc() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::R_brc) return false;
        else return true;
    }

    bool Parser::expKey() {
        if (actualToken==lastToken) return false;
        if (actualToken->getType() != TokenType::If) return false;
        else return true;
    }



    void Parser::parseAs(std::vector<Token>& tokens) {

        if (tokens.begin()->getType()!= TokenType::Identifier)
        {
            return;
        }


        std::list<Expr *> expression;

        Node* node1 = new Node(new ExpAS(tokens.front().getValue()));


        for (int i=2; i<tokens.size(); i++)
        {
            auto x = tokens[i];
            if (x.getType()==TokenType::Identifier)
                expression.push_back(new ExpID(x.getValue()));
            else if (x.getType()==TokenType::Operator)
            {

                if (x.getValue()=="+")
                    expression.push_back(new ExpSUM(x.getValue()));
                else if (x.getValue()=="-")
                    expression.push_back(new ExpSUB(x.getValue()));
                else if (x.getValue()=="/")
                    expression.push_back(new ExpDIV(x.getValue()));
                else if (x.getValue()=="*")
                    expression.push_back(new ExpMULT(x.getValue()));
            }
            else if (x.getType()==TokenType::Int_D)
                expression.push_back(new ExpINT(x.getValue()));
            else if (x.getType()==TokenType::Double_D)
                expression.push_back(new ExpDOUB(x.getValue()));
            else if (x.getType()==TokenType::L_br)
                expression.push_back(new ExpLBR(x.getValue()));
            else if (x.getType()==TokenType::L_brc)
                expression.push_back(new ExpLBRC(x.getValue()));
            else if (x.getType()==TokenType::R_br)
                expression.push_back(new ExpRBR(x.getValue()));
            else if (x.getType()==TokenType::R_brc)
                expression.push_back(new ExpRBRC(x.getValue()));
        }

        node1->addChildBack(addNodeExpr(ReversePolishNotation(expression)));
        root->addChildBack(node1);

    }

    bool Parser::IsOperator(ExprType type)
    {
        if (type!=EXP_ID && type!=EXP_INT && type!=EXP_DOUBLE && type!=EXP_STRING &&
        type!=EXP_WHILE && type!=EXP_OP_ASSIGN_VAR
        && type!=EXP_IF && type!=EXP_BRACKET_L && type!= EXP_BRACKET_R) return true;
        return false;
    }

    int Parser::Priority(ExprType type)
    {
        switch (type) {
            case EXP_BRACKET_L:
            case EXP_BRACKET_R:
                return 5;
            case EXP_OP_NOT_EQUAL:
            case EXP_OP_EQUAL:
                return 4;
            case EXP_OP_SMALLER:
            case EXP_OP_MORE:
            case EXP_MOREEQ:
            case EXP_SMALEQ:
                return 3;
            case EXP_OP_MULTIPLICATION:
            case EXP_OP_DIVISION:
                return 2;
            case EXP_OP_SUB:
            case EXP_OP_SUM:
                return 1;
        }
        return 0;
    }

std::list<Expr*> Parser::ReversePolishNotation(std::list <Expr *> expression)
{
   std::list <Expr*> reverce;
   std::stack<Expr*> mstack;
   for (auto* expression: expression) {
           auto type = expression->getType();

   if (type==EXP_ID || type==EXP_DOUBLE || type==EXP_INT || type==EXP_OP_ASSIGN_VAR)
       reverce.push_back(expression);

   //  ?????? ?????????????????? ???????????????? ?? ???????????????? ?????????????? :
   if (IsOperator(type))
   {
       //???????? ?? ?????????? ?????? ???????????????? ?????? ?????????????? ??????????????????
       //?????????? ???????????????? ?????????????????????? ????????????, ???????????????? ???????????????? ?? ????????;
       if (mstack.empty() || mstack.top()->getType() == EXP_BRACKET_L)
           mstack.push(expression);
       //  ???????? ?????????? ???????????????? ?????????? ??????????????* ??????????????????, ?????? ?????????????? ???????????????? ?? ??????????, ???? ?????????? ???????????????? ???????????????? ?? ????????;
       else if (Priority(mstack.top()->getType()) < Priority(type)) //&&&&&&?? ???? ????
           mstack.push(expression);
       //  ???????? ?????????? ???????????????? ?????????? ?????????????? ?????? ???????????? ??????????????????, ?????? ?????????????? ???????????????? ?? ??????????, ???? ????????????????, ?????????????????????? ?? ??????????,
       //???? ?????????????????? ?????????????????????? ???????????? ?????? ???? ???????????????? ?? ?????????????????????? ??????????????, ?????? ?? ?????????? ????????????????, ?????????????????????????????? ?? ?????????????????????? ????????????, ?? ?????????? ???????????????? ???????????????? ?? ????????.
       else if (Priority(mstack.top()->getType()) >= Priority(type))
       {
           while (!mstack.empty() && mstack.top()->getType() != EXP_BRACKET_L && !(Priority(mstack.top()->getType()) < Priority(type)))
           {
               reverce.push_back(mstack.top());
               mstack.pop();
           }
           mstack.push(expression);
       }
   }

   //  ?????????????????????? ???????????? ???????????????? ?? ????????.
   if (type == EXP_BRACKET_L)
       mstack.push(expression);

   //  ?????????????????????? ???????????? ?????????????????????? ???? ?????????? ?? ?????????????????????? ???????????? ?????? ???????????????? ???? ?????????????????? ?????????????????????? ????????????, ?????????????????????? ???????????? ?????????????????? ???? ??????????.
   if (type == EXP_BRACKET_R)
   {
       while (!mstack.empty() && mstack.top()->getType() != EXP_BRACKET_L)
       {

           reverce.push_back(mstack.top());
           mstack.pop();
       }
       if (mstack.top()->getType() == EXP_BRACKET_L)
           mstack.pop();
   }
    }
    //  ?????????? ????????, ?????? ???? ?????????????????? ???? ?????????? ?????????????????? ??????????????????, ????????????????, ???????????????????? ?? ??????????, ?????????????????????????????? ?? ?????????????????????? ??????????????????.
    while (!mstack.empty())
    {
        reverce.push_back(mstack.top());
        mstack.pop();
    }

    return reverce;

}

Node* Parser::addNodeExpr(const std::list<Expr*>& postfix) {

    std::stack<Node *> st;

    for (const auto &exp: postfix) {
        Node *node = new Node(exp);
        if (IsOperator(node->getType())) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        }
        st.push(node);
    }
    Node* result = st.top();
    st.pop();
    return result;
}

void Parser::parseIF(std::vector<Token>& tokens) {
    std::list<Expr *> expression;
    if (tokens.begin()->getValue()!= "if")
    {
        return;
    }

    for (auto x : tokens) {

        if (x.getType() == TokenType::Identifier)
            expression.push_back(new ExpID(x.getValue()));
        if (x.getType() == TokenType::Operator) {
            if (x.getValue() == "=")
                expression.push_back(new ExpAS(x.getValue()));
            if (x.getValue() == "+")
                expression.push_back(new ExpSUM(x.getValue()));
            if (x.getValue() == "-")
                expression.push_back(new ExpSUB(x.getValue()));
            if (x.getValue() == "/")
                expression.push_back(new ExpDIV(x.getValue()));
            if (x.getValue() == "*")
                expression.push_back(new ExpMULT(x.getValue()));
            if (x.getValue() == "!")
                expression.push_back(new ExpNOT(x.getValue()));
            if (x.getValue() == "<")
                expression.push_back(new ExpSMALLER(x.getValue()));
            if (x.getValue() == ">")
                expression.push_back(new ExpMORE(x.getValue()));

        }
        if (x.getType() == TokenType::Int_D)
            expression.push_back(new ExpINT(x.getValue()));
        if (x.getType() == TokenType::Semicolons)
            expression.push_back(new ExpSEM(x.getValue()));
        if (x.getType() == TokenType::Double_D)
            expression.push_back(new ExpDOUB(x.getValue()));
        if (x.getType() == TokenType::L_br)
            expression.push_back(new ExpLBR(x.getValue()));
        if (x.getType() == TokenType::L_brc)
            expression.push_back(new ExpLBRC(x.getValue()));
        if (x.getType() == TokenType::R_br)
            expression.push_back(new ExpRBR(x.getValue()));
        if (x.getType() == TokenType::R_brc)
            expression.push_back(new ExpRBRC(x.getValue()));
        if (x.getType()== TokenType::Op) {
            if (x.getValue() == "==")
                expression.push_back(new ExpCOMPARE(x.getValue()));
            if (x.getValue() == "<=")
                expression.push_back(new ExpSMALEQ(x.getValue()));
            if (x.getValue() == ">=")
                expression.push_back(new ExpMOREEQ(x.getValue()));
            if (x.getValue() == "&&")
                expression.push_back(new ExpLOGUM(x.getValue()));
            if (x.getValue() == "||")
                expression.push_back(new ExpLOGOR(x.getValue()));
            if (x.getValue() == "!=")
                expression.push_back(new ExpNOTEQ(x.getValue()));
        }
    }
    expression.pop_front();
    std::list<Expr *> comparation;
    int i=0;
    for (auto x: expression)
    {
        if (x->getType()!=EXP_LBRC)
        {
            comparation.push_back(x);
            i++;
        }
        else break;
    }
    for (int m=0; m<i; m++)
    {
        expression.pop_front();
    }
    comparation.pop_back();
    auto condition = addNodeExpr(ReversePolishNotation(comparation));
    Node *body = new Node(new ExpBlock("if"));
    comparation.clear();
    expression.pop_front();
    expression.pop_back();
    Parser parser(body);
    std::vector <Token> tokensBlock;
    bool flag = false;
    for (auto token : tokens)
    {
        if (token.getValue()=="}")
        {
            break;
        }
        else if (flag)
        {
            tokensBlock.push_back(token);
        }
        else if (token.getValue()=="{")
        {
            flag=true;
        }
    }
    parser.addTokens(tokensBlock);
    root->addChildBack(new Node(new ExpIF(condition, body)));
}

    void Parser::parseWHILE(std::vector<Token>& tokens) {
        std::list<Expr *> expression;
        if (tokens.begin()->getValue()!= "while")
        {
            return;
        }

        for (auto x : tokens) {

            if (x.getType() == TokenType::Identifier)
                expression.push_back(new ExpID(x.getValue()));
            if (x.getType() == TokenType::Operator) {
                if (x.getValue() == "=")
                    expression.push_back(new ExpAS(x.getValue()));
                if (x.getValue() == "+")
                    expression.push_back(new ExpSUM(x.getValue()));
                if (x.getValue() == "-")
                    expression.push_back(new ExpSUB(x.getValue()));
                if (x.getValue() == "/")
                    expression.push_back(new ExpDIV(x.getValue()));
                if (x.getValue() == "*")
                    expression.push_back(new ExpMULT(x.getValue()));
                if (x.getValue() == "!")
                    expression.push_back(new ExpNOT(x.getValue()));
                if (x.getValue() == "<")
                    expression.push_back(new ExpSMALLER(x.getValue()));
                if (x.getValue() == ">")
                    expression.push_back(new ExpMORE(x.getValue()));

            }
            if (x.getType() == TokenType::Int_D)
                expression.push_back(new ExpINT(x.getValue()));
            if (x.getType() == TokenType::Semicolons)
                expression.push_back(new ExpSEM(x.getValue()));
            if (x.getType() == TokenType::Double_D)
                expression.push_back(new ExpDOUB(x.getValue()));
            if (x.getType() == TokenType::L_br)
                expression.push_back(new ExpLBR(x.getValue()));
            if (x.getType() == TokenType::L_brc)
                expression.push_back(new ExpLBRC(x.getValue()));
            if (x.getType() == TokenType::R_br)
                expression.push_back(new ExpRBR(x.getValue()));
            if (x.getType() == TokenType::R_brc)
                expression.push_back(new ExpRBRC(x.getValue()));
            if (x.getType()== TokenType::Op) {
                if (x.getValue() == "==")
                    expression.push_back(new ExpCOMPARE(x.getValue()));
                if (x.getValue() == "<=")
                    expression.push_back(new ExpSMALEQ(x.getValue()));
                if (x.getValue() == ">=")
                    expression.push_back(new ExpMOREEQ(x.getValue()));
                if (x.getValue() == "&&")
                    expression.push_back(new ExpLOGUM(x.getValue()));
                if (x.getValue() == "||")
                    expression.push_back(new ExpLOGOR(x.getValue()));
                if (x.getValue() == "!=")
                    expression.push_back(new ExpNOTEQ(x.getValue()));
            }
        }
        expression.pop_front();
        std::list<Expr *> comparation;
        int i=0;
        for (auto x: expression)
        {
            if (x->getType()!=EXP_LBRC)
            {
                comparation.push_back(x);
                i++;
            }
            else break;
        }
        for (int m=0; m<i; m++)
        {
            expression.pop_front();
        }
        comparation.pop_back();
        auto condition = addNodeExpr(ReversePolishNotation(comparation));
        Node *body = new Node(new ExpBlock("while"));
        comparation.clear();
        expression.pop_front();
        expression.pop_back();
        Parser parser(body);
        std::vector <Token> tokensBlock;
        bool flag = false;
        for (auto token : tokens)
        {
            if (token.getValue()=="}")
            {
                break;
            }
            else if (flag)
            {
                tokensBlock.push_back(token);
            }
            else if (token.getValue()=="{")
            {
                flag=true;
            }
        }
        parser.addTokens(tokensBlock);
        root->addChildBack(new Node(new ExpWHILE(condition, body)));
}

void Parser::parsePRINT(std::vector<Token>& tokens)
{
    if (tokens.begin()->getValue()!= "print")
    {
        return;
    }

    root->addChildBack(new Node(new ExpPRINT(tokens[1].getValue())));

}

Node* Parser::getNode()
{
    return root;
}
