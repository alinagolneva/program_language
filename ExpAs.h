//
// Created by Alina on 09.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPAS_H
#define PROGRAM_LANGUAGE_EXPAS_H

#include <string>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpAS final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
     ExpAS(std::string& value);

    ExpAS(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPAS_H
