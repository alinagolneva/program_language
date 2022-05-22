//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPDIV_H
#define PROGRAM_LANGUAGE_EXPDIV_H

#include <iostream>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpDIV final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpDIV(std::string value);

};



#endif //PROGRAM_LANGUAGE_EXPDIV_H
