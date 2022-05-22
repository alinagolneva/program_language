//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPNOTEQ_H
#define PROGRAM_LANGUAGE_EXPNOTEQ_H


#include <string>
#include "Expr.h"
#include "InterpreterArgs.h"
class ExpNOTEQ final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpNOTEQ(std::string& value);

    ExpNOTEQ(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPNOTEQ_H
