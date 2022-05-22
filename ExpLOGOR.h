//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPLOGOR_H
#define PROGRAM_LANGUAGE_EXPLOGOR_H
#include "InterpreterArgs.h"

#include <string>
#include "Expr.h"

class ExpLOGOR final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpLOGOR(std::string& value);

    ExpLOGOR(std::string basicString);
};

#endif //PROGRAM_LANGUAGE_EXPLOGOR_H
