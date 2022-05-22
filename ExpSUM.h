//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPSUM_H
#define PROGRAM_LANGUAGE_EXPSUM_H

#include <iostream>
#include "Expr.h"


class ExpSUM final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    virtual std::string toString() const;
    std::string id;

public:
    ExpSUM(std::string& value);

    ExpSUM(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPSUM_H
