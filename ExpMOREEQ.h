//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPMOREEQ_H
#define PROGRAM_LANGUAGE_EXPMOREEQ_H

#include <string>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpMOREEQ final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpMOREEQ(std::string& value);

    ExpMOREEQ(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPMOREEQ_H
