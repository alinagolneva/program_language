//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_VARBOOL_H
#define PROGRAM_LANGUAGE_VARBOOL_H


#include "Var.h"

class VarBool final: public Var {
private:
    const bool value;

public:
    explicit VarBool(const bool value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;

    [[nodiscard]] explicit operator bool            () const override;
    [[nodiscard]] explicit operator long long       () const override;
    [[nodiscard]] explicit operator long double     () const override;
    [[nodiscard]] explicit operator std::string     () const override;

    [[nodiscard]] Var* copy() const override;
};

#endif //PROGRAM_LANGUAGE_VARBOOL_H
