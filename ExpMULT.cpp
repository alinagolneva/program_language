//
// Created by Alina on 10.05.2022.
//

#include "ExpMULT.h"
#include "InterpreterArgs.h"
ExpMULT::ExpMULT(std::string value):

        Expr(EXP_OP_MULTIPLICATION), id(value) {}

void ExpMULT::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 * *arg2);

        delete arg1;
        delete arg2;
    } else return;
}

std::string ExpMULT::toString() const {
    return "*";
}