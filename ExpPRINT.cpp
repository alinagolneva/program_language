//
// Created by Alina on 24.05.2022.
//

#include <iostream>
#include "ExpPRINT.h"
ExpPRINT::ExpPRINT(std::string value):

        Expr(EXP_PRINT), id(value) {}

std::string ExpPRINT::toString() const {
    return id;
}

void ExpPRINT::action(const InterpreterArgs &args) const {
    for (auto scope: args.variablesGlobal) {
        if (callVariableFrom(scope, args.stack)) {
            return;
        }
    }

    if (!callVariableFrom(args.variables, args.stack)) {
        return;
    }
}

bool ExpPRINT::callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        std::cout << std::string(*it->second);
        return true;
    }
    return false;
}