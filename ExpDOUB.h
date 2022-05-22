//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPDOUB_H
#define PROGRAM_LANGUAGE_EXPDOUB_H
#include <iostream>
#include "Expr.h"


class ExpDOUB final: public Expr {

private:
    const long double value;
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;

public:

    ExpDOUB(std::string value);


};


#endif //PROGRAM_LANGUAGE_EXPDOUB_H
