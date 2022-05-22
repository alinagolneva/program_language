//
// Created by Alina on 21.05.2022.
//

#include "Var.h"
#include "VarBool.h"


Var::Var(const VarType& type) :
        type(type) {}

Var::~Var() = default;

std::string Var::getTypeName() const {
    switch (type) {
        case BOOL_VAR:
            return "'bool'";
        case INTEGER_VAR:
            return "'int'";
        case DOUBLE_VAR:
            return "'double'";
        case STRING_VAR:
            return "'string'";
    }
    return NULL;
}


Var* Var::operator + (const Var&) const {

    return NULL;
}

Var* Var::operator - (const Var&) const {
    return NULL;
}

Var* Var::operator * (const Var&) const {
    return NULL;
}

Var* Var::operator / (const Var&) const {
    return NULL;
}

Var* Var::operator < (const Var & second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool((std::string)*this < (std::string) second);
    }
    else {
        return new VarBool((long double)*this < (long double)second);
    }
}

Var* Var::operator <= (const Var & second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool((std::string) * this <= (std::string) second);
    }
    else {
        return new VarBool((long double)*this <= (long double)second);
    }
}

Var* Var::operator > (const Var & second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool((std::string)*this > (std::string)second);
    }
    else {
        return new VarBool((long double)*this > (long double)second);
    }
}

Var* Var::operator >= (const Var & second) const {
    if (second.getType() == STRING_VAR) {
        return new VarBool((std::string) * this >= (std::string) second);
    }
    else {
        return new VarBool((long double)*this >= (long double)second);
    }
}

Var* Var::operator == (const Var & second) const {
    return new VarBool(((bool)*this != (bool)second));
}

Var* Var::operator ! () const {
    return new VarBool((!bool(*this)));
}

Var* Var::operator != (const Var & second) const {
    return new VarBool(((bool)*this == (bool)second));
}

Var* Var::operator && (const Var & second) const {
    return new VarBool(((bool)*this && (bool)second));
}

Var* Var::operator || (const Var & second) const {
    return new VarBool(((bool)*this || (bool)second));
}

Var::VarType Var::getType() const {
    return type;
}

Var::operator bool() const {
    return NULL;
}

Var::operator long long() const {
    return NULL;
}


Var::operator long double() const {
    return NULL;
}

