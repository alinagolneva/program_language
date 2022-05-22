//
// Created by Alina on 22.05.2022.
//

#ifndef PROGRAM_LANGUAGE_INTERPRETERARGS_H
#define PROGRAM_LANGUAGE_INTERPRETERARGS_H


#include <list>
#include <map>
#include <stack>
#include <string>
#include "variables/Var.h"


class Node;

struct InterpreterArgs {

    std::list<std::map<std::string, Var*>*>& variablesGlobal;
    std::map<std::string, Var*>* variables;

    std::stack<Var*>& stack;

    InterpreterArgs(
            std::list<std::map<std::string, Var*>*>& variablesGlobal,
            std::map<std::string, Var*>* variables,
            std::stack<Var*>& stack
    );
};

#endif //PROGRAM_LANGUAGE_INTERPRETERARGS_H
