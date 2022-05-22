//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPCOMPARE_H
#define PROGRAM_LANGUAGE_EXPCOMPARE_H


#include <string>
#include "Expr.h"

class ExpCOMPARE final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    virtual std::string toString() const;
    std::string id;

public:
    ExpCOMPARE(std::string& value);

    ExpCOMPARE(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPCOMPARE_H
