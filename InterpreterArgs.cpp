//
// Created by Alina on 22.05.2022.
//

#include "InterpreterArgs.h"

InterpreterArgs::InterpreterArgs(
std::list<std::map<std::string, Var*>*>& variablesGlobal,
std::map<std::string, Var*>* variables,
        std::stack<Var*>& stack
):
variablesGlobal(variablesGlobal),
stack(stack) {
    this->variables = variables;
}