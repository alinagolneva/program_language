//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPRBR_H
#define PROGRAM_LANGUAGE_EXPRBR_H

#include <iostream>
#include "Expr.h"

class ExpRBR final: public Expr {
private:
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;
    std::string id;

public:
    ExpRBR(std::string& value);

    ExpRBR(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPRBR_H
