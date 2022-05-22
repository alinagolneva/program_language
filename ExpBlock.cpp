//
// Created by Alina on 21.05.2022.
//

#include "ExpBlock.h"


ExpBlock::ExpBlock(const std::string& name):
        Expr(EXP_CODE_BLOCK),
        name(name) {}

std::string ExpBlock::toString() const {
    return name;
}