//
// Created by Alina on 09.05.2022.
//

#include "ExpAs.h"
#include "Expr.h"

ExpAS::ExpAS(std::string value):

    Expr(EXP_OP_EQUAL), id(value) {}

void ExpAS::action(const InterpreterArgs& args) const {
    if (!args.stack.empty()) {
        auto val = args.stack.top();
        args.stack.pop();

        for (auto scope: args.variablesGlobal) {
            auto it = scope->find(id);
            if (it != scope->end()) {
                auto var = it->second;
                scope->insert_or_assign(id, val);
                delete var;
                return;
            }
        }

        auto it = args.variables->find(id);
        if (it != args.variables->end()) {
            auto var = it->second;
            args.variables->insert_or_assign(id, val);
            delete var;
        } else {
            args.variables->insert_or_assign(id, val);
        }
    } else return;
}

std::string ExpAS::toString() const {
    return id;
}

