//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPRBRC_H
#define PROGRAM_LANGUAGE_EXPRBRC_H

#include <iostream>
#include "Expr.h"

class ExpRBRC final: public Expr {
private:
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;
    std::string id;

public:
    ExpRBRC(std::string& value);

    ExpRBRC(std::string basicString);
};



#endif //PROGRAM_LANGUAGE_EXPRBRC_H
