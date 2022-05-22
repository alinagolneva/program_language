//
// Created by Alina on 17.05.2022.
//

#ifndef PROGRAM_LANGUAGE_NODE_H
#define PROGRAM_LANGUAGE_NODE_H


#include <list>
#include "Expr.h"

class Node {
private:
    const Expr* expression;
    std::list<Node*> children;

public:
    explicit Node(const Expr*);
    Node(const Expr*, const std::list<Node*>&);
    ~Node();

    ExprType getType();
    [[nodiscard]] const Expr* getExpression() const;

    void addChildFront(Node *child);
    void addChildBack(Node *child);

    [[nodiscard]] std::list<Node*> getChildren() const;

};


#endif //PROGRAM_LANGUAGE_NODE_H
