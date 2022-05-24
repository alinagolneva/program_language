//
// Created by Alina on 09.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPR_H
#define PROGRAM_LANGUAGE_EXPR_H

#include <string>
#include "InterpreterArgs.h"
enum ExprType {

    EXP_ID,
    EXP_INT,
    EXP_DOUBLE,
    EXP_STRING,
    EXP_PRINT,
    EXP_OP_MULTIPLICATION,
    EXP_OP_DIVISION,
    EXP_OP_SUM,
    EXP_OP_SUB,
    EXP_OP_SMALLER,
    EXP_COMPARE,
    EXP_OP_EQUAL,
    EXP_OP_MORE,
    EXP_SMALEQ,
    EXP_MOREEQ,
    EXP_OP_NOT_EQUAL,
    EXP_LOGICAL_AND,
    EXP_LOGICAL_OR,
    EXP_OP_NOT,
    EXP_OP_ASSIGN_VAR,
    EXP_LBRC,
    EXP_RBRC,
    EXP_OP_SEMICOLON,
    EXP_CODE_BLOCK,
    EXP_IF,
    EXP_WHILE,


    EXP_BRACKET_L,
    EXP_BRACKET_R,
};

class Expr {

    protected:
    ExprType Exprtype;


    public:
        Expr(ExprType type);
        ExprType getType() const;
    virtual void action(const InterpreterArgs& args) const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};



#endif //PROGRAM_LANGUAGE_EXPR_H
