//
// Created by Alina on 10.05.2022.
//

#include "ExpINT.h"
#include "variables/VarInteger.h"


ExpINT::ExpINT(std::string value):

        Expr(EXP_INT), value(std::stoll(value)) {}

void ExpINT::action(const InterpreterArgs& args) const {
    args.stack.push(new VarInteger(value));
}

std::string ExpINT::toString() const {
    return std::to_string(value);
}