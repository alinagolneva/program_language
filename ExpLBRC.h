//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPLBRC_H
#define PROGRAM_LANGUAGE_EXPLBRC_H

#include <iostream>
#include "Expr.h"

class ExpLBRC final: public Expr {
private:
    void action(const InterpreterArgs& args) const {};
    std::string toString() const;
    std::string id;

public:
    ExpLBRC(std::string& value);

    ExpLBRC(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPLBRC_H
