//
// Created by Alina on 17.05.2022.
//

#include "ExpIF.h"
#include "Interpreter.h"

ExpIF::ExpIF(
        const Node* blockCondition,
        const Node* blockExecute):
        Expr(EXP_IF),
        blockCondition(blockCondition),
        blockExecute(blockExecute)
{}

void ExpIF::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Interpreter compilerCondition(args.variablesGlobal);
    compilerCondition.execute(blockCondition);

    auto condition = compilerCondition.getStack().top();
    compilerCondition.getStack().pop();

    if ((bool) *condition) {
        //args.functions.push_front(functions);

        Interpreter compilerBlock(args.variablesGlobal);
        compilerBlock.execute(blockExecute);

    }

    args.variablesGlobal.pop_front();
    delete condition;
}

std::string ExpIF::toString() const {
    return NULL; // "if\n        " + ifBrascet->toString(2) + "\n        execute " + body->toString(2);
}