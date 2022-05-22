//
// Created by Alina on 21.05.2022.
//

#include "VarBool.h"
#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"


VarBool::VarBool(const bool value):
        Var(BOOL_VAR),
        value(value) {}

Var* VarBool::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
            return new VarBool((bool) *this || (bool) second);
        case INTEGER_VAR:
            return new VarInteger((long long) *this + (long long) second);
        case DOUBLE_VAR:
            return new VarDouble((long double) *this + (long double) second);
        case STRING_VAR:
            return new VarString((std::string) *this + (std::string) second);


    }
}

Var* VarBool::operator - (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger((long long) *this - (long long) second);
        case DOUBLE_VAR:
            return new VarDouble((long double) *this - (long double) second);
        case STRING_VAR:
            return second.operator - (*this);
    }
}

Var* VarBool::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger((long long) *this * (long long) second);
        case DOUBLE_VAR:
            return new VarDouble((long double) *this * (long double) second);
        case STRING_VAR:
            return second.operator * (*this);
    }
}

Var* VarBool::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble((long double) *this / (long double) second);
    }
}

VarBool::operator bool() const {
    return value;
}

VarBool::operator long long() const {
    return (long long) value;
}

VarBool::operator long double() const {
    return (long double) value;
}

VarBool::operator std::string() const {
    return (value ? "true" : "false");
}

Var *VarBool::copy() const {
    return new VarBool(value);
}