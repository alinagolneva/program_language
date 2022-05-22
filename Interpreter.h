//
// Created by Alina on 22.05.2022.
//

#ifndef PROGRAM_LANGUAGE_INTERPRETER_H
#define PROGRAM_LANGUAGE_INTERPRETER_H


#include <list>
#include <map>
#include <stack>
#include "Node.h"
#include "variables/Var.h"


class Interpreter final {
private:


    std::list<std::map<std::string, Var*>*> variablesGlobal;
    std::map<std::string, Var*>* variables;

    std::stack<Var*> stack;


public:
    explicit Interpreter();
    explicit Interpreter(
            const std::list<std::map<std::string, Var*>*>& variablesGlobal
    );

    ~Interpreter();

    void execute(const Node*);

    [[nodiscard]] const std::map<std::string, Var*>* getVariables() const;
    std::stack<Var*>& getStack();
};

#endif //PROGRAM_LANGUAGE_INTERPRETER_H
