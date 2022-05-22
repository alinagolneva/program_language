//
// Created by Alina on 17.05.2022.
//

#include "ExpCOMPARE.h"
#include "Expr.h"

ExpCOMPARE::ExpCOMPARE(std::string value):

        Expr(EXP_COMPARE), id(value) {}

void ExpCOMPARE::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 == *arg2);

        delete arg1;
        delete arg2;
    } else return;
}

std::string ExpCOMPARE::toString() const {
    return "==";
}