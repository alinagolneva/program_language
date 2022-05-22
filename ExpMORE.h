//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPMORE_H
#define PROGRAM_LANGUAGE_EXPMORE_H
#include "InterpreterArgs.h"

#include <string>
#include "Expr.h"

class ExpMORE final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpMORE(std::string& value);

    ExpMORE(std::string basicString);
};



#endif //PROGRAM_LANGUAGE_EXPMORE_H
