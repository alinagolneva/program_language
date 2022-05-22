//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_VARDOUBLE_H
#define PROGRAM_LANGUAGE_VARDOUBLE_H


#include "Var.h"

class VarDouble final: public Var {
private:
    const long double value;

public:
    explicit VarDouble(const long double value);

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

#endif //PROGRAM_LANGUAGE_VARDOUBLE_H
