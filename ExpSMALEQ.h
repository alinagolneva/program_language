//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPSMALEQ_H
#define PROGRAM_LANGUAGE_EXPSMALEQ_H


#include <string>
#include "Expr.h"

class ExpSMALEQ final: public Expr {
private:
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;
    std::string id;

public:
    ExpSMALEQ(std::string& value);

    ExpSMALEQ(std::string basicString);
};



#endif //PROGRAM_LANGUAGE_EXPSMALEQ_H
