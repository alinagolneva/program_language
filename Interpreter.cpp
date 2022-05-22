//
// Created by Alina on 22.05.2022.
//

#include "Interpreter.h"
#include "InterpreterArgs.h"

Interpreter::Interpreter() {
    variables = new std::map<std::string, Var*>();
}

Interpreter::Interpreter(
const std::list<std::map<std::string, Var*>*>& variablesGlobal
):

variablesGlobal(variablesGlobal) {
    variables = new std::map<std::string, Var*>();
}

Interpreter::~Interpreter() {
    for (const auto& var: *variables) {
        delete var.second;
    }
    delete variables;
    while (!stack.empty()) {
        auto var = stack.top();
        stack.pop();
        delete var;
    }
}

void Interpreter::execute(const Node* tree) {
    for (auto node: tree->getChildren()) {
        execute(node);

    }

    tree->getExpression()->action(InterpreterArgs(variablesGlobal, variables, stack));
}

const std::map<std::string, Var*>* Interpreter::getVariables() const {
    return variables;
}

std::stack<Var*>& Interpreter::getStack() {
    return stack;
}