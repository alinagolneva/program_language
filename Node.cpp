//
// Created by Alina on 17.05.2022.
//

#include "Node.h"

Node::Node(const Expr* expression):
        expression(expression) {}

Node::Node(const Expr* expression, const std::list<Node*>& children):
        expression(expression),
        children(children) {}

Node::~Node() {
    delete expression;
    for (auto child: children) {
        delete child;
    }
}

ExprType Node::getType() const {
    return expression->getType();
}

void Node::addChildFront(Node* child) {
    children.push_front(child);
}

void Node::addChildBack(Node* child) {
    children.push_back(child);
}

std::list<Node *> Node::getChildren() const {
    return children;
}

const Expr* Node::getExpression() const {
    return expression;
}
