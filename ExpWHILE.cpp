//
// Created by Alina on 17.05.2022.
//

#include <string>
#include "ExpWHILE.h"
#include "Expr.h"
#include "Expr.h"
#include "Interpreter.h"
ExpWHILE::ExpWHILE(
        const Node* blockCondition,
        const Node* blockExecute):
        Expr(EXP_WHILE),
        blockCondition(blockCondition),
        blockExecute(blockExecute)
{}

void ExpWHILE::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Interpreter compilerCondition( args.variablesGlobal);
    compilerCondition.execute(blockCondition);

    auto condition = compilerCondition.getStack().top();
    compilerCondition.getStack().pop();

    while ((bool) *condition) {


        Interpreter compilerExecute(args.variablesGlobal);
        compilerExecute.execute(blockExecute);



        compilerCondition.execute(blockCondition);
        delete condition;
        condition = compilerCondition.getStack().top();
        compilerCondition.getStack().pop();
    }

    args.variablesGlobal.pop_front();
    delete condition;
}


std::string ExpWHILE::toString() const {
    return NULL;// "while\n        " + whileBrascet->toString(2) + "\n        execute " + body->toString(2);
}