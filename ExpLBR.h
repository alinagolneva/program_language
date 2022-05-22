//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPLBR_H
#define PROGRAM_LANGUAGE_EXPLBR_H

#include <iostream>
#include "Expr.h"

class ExpLBR final: public Expr {
private:
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;
    std::string id;

public:
    ExpLBR(std::string& value);

    ExpLBR(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPLBR_H
