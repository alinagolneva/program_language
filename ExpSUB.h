//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPSUB_H
#define PROGRAM_LANGUAGE_EXPSUB_H
#include <iostream>
#include "Expr.h"

class ExpSUB final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:

    ExpSUB(std::string basicString);
};

#endif //PROGRAM_LANGUAGE_EXPSUB_H
