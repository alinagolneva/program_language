//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPLOGUM_H
#define PROGRAM_LANGUAGE_EXPLOGUM_H

#include "InterpreterArgs.h"
#include <string>
#include "Expr.h"

class ExpLOGUM final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpLOGUM(std::string& value);

    ExpLOGUM(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPLOGUM_H
