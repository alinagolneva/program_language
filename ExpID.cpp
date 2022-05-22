//
// Created by Alina on 10.05.2022.
//

#include "ExpID.h"

ExpID::ExpID(std::string value):

        Expr(EXP_ID), id(value) {}

std::string ExpID::toString() const {
    return id;
}

void ExpID::action(const InterpreterArgs &args) const {
    for (auto scope: args.variablesGlobal) {
        if (callVariableFrom(scope, args.stack)) {
            return;
        }
    }

    if (!callVariableFrom(args.variables, args.stack)) {
        return;
    }
}

bool ExpID::callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const {
    auto it = container->find(id);
    if (it != container->end()) {
        stack.push(it->second->copy());
        return true;
    }
    return false;
}