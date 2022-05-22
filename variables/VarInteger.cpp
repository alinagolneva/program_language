//
// Created by Alina on 21.05.2022.
//


#include "VarInteger.h"
#include "VarDouble.h"
#include "VarString.h"




VarInteger::VarInteger(const long long value):
        Var(INTEGER_VAR),
        value(value) {}

Var* VarInteger::operator + (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger((long long) *this + (long long) second);
        case DOUBLE_VAR:
            return new VarDouble((long double) *this  + (long double) second);
        case STRING_VAR:
            return new VarString((std::string) *this + (std::string) second);
    }
}

Var* VarInteger::operator - (const Var& second) const {
    const auto& type = second.getType();

    if (type == BOOL_VAR || type == INTEGER_VAR) {
        return new VarInteger((long long) *this - (long long) second);
    } else if (type == DOUBLE_VAR) {
        return new VarDouble((long double) *this - (long double) second);
    } else {
        return second.operator - (*this);
    }
}

Var* VarInteger::operator * (const Var& second) const {
    switch (second.getType()) {
        case BOOL_VAR:
        case INTEGER_VAR:
            return new VarInteger((long long) *this * (long long) second);
        case DOUBLE_VAR:
            return new VarDouble((long double) *this * (long double) second);
        case STRING_VAR: {
            auto str = (std::string) second;
            std::string result;
            for (int i = 0; i < (long long) *this; i++) {
                result += str;
            }
            return new VarString(result);
        }
    }
}

Var* VarInteger::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble((long double) *this / (long double) second);
    }
}

VarInteger::operator bool() const {
    return (bool) value;
}

VarInteger::operator long long() const {
    return value;
}

VarInteger::operator long double() const {
    return (long double) value;
}

VarInteger::operator std::string() const {
    return std::to_string(value);
}

Var *VarInteger::copy() const {
    return new VarInteger(value);
}