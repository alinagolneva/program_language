//
// Created by Alina on 10.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPINT_H
#define PROGRAM_LANGUAGE_EXPINT_H

#include <iostream>
#include "Expr.h"


class ExpINT final: public Expr {
private:
    const long long value;
    std::string id;
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;

public:
    ExpINT(std::string& value);

    ExpINT(std::string basicString);
};



#endif //PROGRAM_LANGUAGE_EXPINT_H
