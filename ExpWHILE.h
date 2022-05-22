//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPWHILE_H
#define PROGRAM_LANGUAGE_EXPWHILE_H



#include <string>
#include <map>
#include "Expr.h"
#include "Node.h"

class ExpWHILE final: public Expr {

private:
    const Node* blockCondition;
    const Node* blockExecute;
    std::map<std::string, Node*>* functions;
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;

public:
    ExpWHILE(
            const Node* blockCondition,
            const Node* blockExecute);


};
#endif //PROGRAM_LANGUAGE_EXPWHILE_H
