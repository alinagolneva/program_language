//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_EXPIF_H
#define PROGRAM_LANGUAGE_EXPIF_H


#include <string>
#include "Expr.h"
#include "Node.h"

class ExpIF final: public Expr {

    private:
    const Node* blockCondition;
    const Node* blockExecute;
    void action(const InterpreterArgs& args) const override;
    std::string toString() const;

    public:
        ExpIF(
        const Node* blockCondition,
        const Node* blockExecute);
    };




#endif //PROGRAM_LANGUAGE_EXPIF_H
