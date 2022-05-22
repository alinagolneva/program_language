//
// Created by Alina on 10.05.2022.
//

#include "ExpLBR.h"
ExpLBR::ExpLBR(std::string value):

        Expr(EXP_BRACKET_L), id(value) {}

std::string ExpLBR::toString() const {
    return id;
}