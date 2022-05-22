//
// Created by Alina on 17.05.2022.
//

#include "ExpLOGUM.h"
#include "InterpreterArgs.h"
ExpLOGUM::ExpLOGUM(std::string value):

        Expr(EXP_LOGICAL_AND), id(value) {}

void ExpLOGUM::action(const InterpreterArgs &args) const{
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(*arg1 && *arg2);

        delete arg1;
        delete arg2;
    } else return;
}

std::string ExpLOGUM::toString() const {
    return "&&";
}