//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPSMALLER_H
#define PROGRAM_LANGUAGE_EXPSMALLER_H


#include <string>
#include "Expr.h"

class ExpSMALLER final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpSMALLER(std::string& value);

    ExpSMALLER(std::string basicString);
};


#endif //PROGRAM_LANGUAGE_EXPSMALLER_H
