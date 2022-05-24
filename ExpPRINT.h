//
// Created by Alina on 24.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPPRINT_H
#define PROGRAM_LANGUAGE_EXPPRINT_H

#include <string>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpPRINT final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;
    bool callVariableFrom(std::map<std::string, Var*>* container, std::stack<Var*>& stack) const;

public:
    ExpPRINT(std::string& value);

    ExpPRINT(std::string basicString);
};

#endif //PROGRAM_LANGUAGE_EXPPRINT_H
