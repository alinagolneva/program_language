//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPBLOCK_H
#define PROGRAM_LANGUAGE_EXPBLOCK_H

#include "InterpreterArgs.h"
#include <string>
#include "Expr.h"
#include "Node.h"

class ExpBlock final: public Expr {
private:
    const std::string name;
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;

public:
    ExpBlock(const std::string &name);
};

#endif //PROGRAM_LANGUAGE_EXPBLOCK_H
