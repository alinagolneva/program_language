//
// Created by Alina on 10.05.2022.
//

#include "ExpLBRC.h"

ExpLBRC::ExpLBRC(std::string value):

        Expr(EXP_LBRC), id(value) {}

std::string ExpLBRC::toString() const {
    return id;
}