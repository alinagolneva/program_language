//
// Created by Alina on 09.05.2022.
//

#include "Expr.h"

Expr::Expr(ExprType type)
         {
             this->Exprtype=type;
         }

ExprType Expr::getType() const {
    return Exprtype;
}


