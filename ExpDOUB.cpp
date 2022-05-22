//
// Created by Alina on 10.05.2022.
//

#include "ExpDOUB.h"
#include "variables/VarDouble.h"

ExpDOUB::ExpDOUB(std::string value):

        Expr(EXP_DOUBLE), value(std::stold(value)) {}

void ExpDOUB::action(const InterpreterArgs& args) const {
    args.stack.push(new VarDouble(value));
}

std::string ExpDOUB::toString() const {
    return std::to_string(value);
}