//
// Created by Alina on 10.05.2022.
//

#include "ExpRBRC.h"
ExpRBRC::ExpRBRC(std::string value):

        Expr(EXP_RBRC), id(value) {}

std::string ExpRBRC::toString() const {
    return id;
}