//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPMULT_H
#define PROGRAM_LANGUAGE_EXPMULT_H

#include <iostream>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpMULT final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpMULT(std::string& value);

    ExpMULT(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPMULT_H
