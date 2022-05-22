//
// Created by Alina on 21.05.2022.
//

#include "VarDouble.h"
#include "VarString.h"


VarDouble::VarDouble(const long double value):
        Var(DOUBLE_VAR),
        value(value) {}

Var* VarDouble::operator + (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return new VarString((std::string) *this + (std::string) second);

    } else {
        return new VarDouble((long double) *this + (long double) second);
    }
}

Var* VarDouble::operator - (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return second.operator - (*this);
    } else {
        return new VarDouble((long double) *this - (long double) second);
    }
}

Var* VarDouble::operator * (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return second.operator * (*this);
    } else {
        return new VarDouble((long double) *this * (long double) second);
    }
}

Var* VarDouble::operator / (const Var& second) const {
    const auto& type = second.getType();
    if (type == STRING_VAR) {
        return second.operator / (*this);
    } else {
        return new VarDouble((long double) *this / (long double) second);
    }
}

VarDouble::operator bool() const {
    return (bool) value;
}

VarDouble::operator long long() const {
    return (long long) value;
}

VarDouble::operator long double() const {
    return value;
}

VarDouble::operator std::string() const {
    return std::to_string(value);
}

Var *VarDouble::copy() const {
    return new VarDouble(value);
}