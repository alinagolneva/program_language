//
// Created by Alina on 17.05.2022.
//

#include "ExpSMALEQ.h"
#include "Expr.h"
#include "InterpreterArgs.h"
ExpSMALEQ::ExpSMALEQ(std::string value):

        Expr(EXP_SMALEQ), id(value) {}

void ExpSMALEQ::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 <= *arg2);

        delete arg1;
        delete arg2;
    } else return;
}

std::string ExpSMALEQ::toString() const {
    return "<=";
}