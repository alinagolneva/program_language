//
// Created by Alina on 21.05.2022.
//

#include "VarString.h"



VarString::VarString(const std::string& value):
        Var(STRING_VAR),
        value(value) {}

Var* VarString::operator + (const Var& second) const {

        return new VarString((std::string) *this + (std::string) second);
    }

Var* VarString::operator - (const Var& second) const {
    return super::operator - (second);
}

Var* VarString::operator * (const Var& second) const {
    if (second.getType() == INTEGER_VAR) {
        auto str = (std::string) *this;
        std::string result;
        for (int i = 0; i < (long long) second; i++) {
            result += str;
        }
        return new VarString(result);
    } else {
        return super::operator * (second);
    }
}

Var* VarString::operator / (const Var& second) const {
    return super::operator/(second);
}

VarString::operator bool() const {
    return !value.empty();
}

VarString::operator long long() const {
    try {
        return std::stoll(value);
    } catch (const std::exception& ex) {
        return super::operator long long();
    }
}

VarString::operator long double() const {
    try {
        return std::stold(value);
    } catch (const std::exception& ex) {
        return super::operator long double();
    }
}

VarString::operator std::string() const {
    return value;
}

Var *VarString::copy() const {
    return new VarString( value);
}