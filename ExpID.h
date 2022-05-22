//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPID_H
#define PROGRAM_LANGUAGE_EXPID_H
#include <iostream>
#include "Expr.h"


class ExpID final: public Expr {
private:
    void action(const InterpreterArgs& args) const;
    bool callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const;
    std::string toString() const;
    std::string id;

public:
    ExpID(std::string& value);

    ExpID(std::string basicString);
};



#endif //PROGRAM_LANGUAGE_EXPID_H
