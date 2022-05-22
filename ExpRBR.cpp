//
// Created by Alina on 10.05.2022.
//

#include "ExpRBR.h"
ExpRBR::ExpRBR(std::string value):

        Expr(EXP_BRACKET_R), id(value) {}

std::string ExpRBR::toString() const {
    return id;
}