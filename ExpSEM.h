//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPSEM_H
#define PROGRAM_LANGUAGE_EXPSEM_H



#include <string>
#include "Expr.h"

class ExpSEM final: public Expr {
private:
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;
    std::string id;

public:
    ExpSEM(std::string& value);

    ExpSEM(std::string basicString);
};

#endif //PROGRAM_LANGUAGE_EXPSEM_H
