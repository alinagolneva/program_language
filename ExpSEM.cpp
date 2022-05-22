//
// Created by Alina on 17.05.2022.
//

#include <string>
#include "ExpSEM.h"
#include "Expr.h"

ExpSEM::ExpSEM(std::string value):

        Expr(EXP_OP_SEMICOLON), id(value) {}

std::string ExpSEM::toString() const {
    return id;
}