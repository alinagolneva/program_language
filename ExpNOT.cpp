//
// Created by Alina on 17.05.2022.
//

#include <string>
#include "ExpNOT.h"
#include "Expr.h"
#include "InterpreterArgs.h"
ExpNOT::ExpNOT(std::string value):

        Expr(EXP_OP_NOT), id(value) {}

void ExpNOT::action(const InterpreterArgs &args) const {
    if (!args.stack.empty()) {
        auto arg = args.stack.top();
        args.stack.pop();
        args.stack.push(!*arg);
        delete arg;
    } else return;
}

std::string ExpNOT::toString() const {
    return "!";
}