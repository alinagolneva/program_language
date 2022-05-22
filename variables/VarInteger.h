//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_VARINTEGER_H
#define PROGRAM_LANGUAGE_VARINTEGER_H


#include "Var.h"

class VarInteger final: public Var {
private:
    const long long value;

public:
    explicit VarInteger(const long long value);

    Var* operator + (const Var&) const override;
    Var* operator - (const Var&) const override;
    Var* operator * (const Var&) const override;
    Var* operator / (const Var&) const override;


    [[nodiscard]] explicit operator bool            () const override;
    [[nodiscard]] explicit operator long long       () const override;
    [[nodiscard]] explicit operator long double     () const override;
    [[nodiscard]] explicit operator std::string     () const override;

    [[nodiscard]] Var* copy() const;
};

#endif //PROGRAM_LANGUAGE_VARINTEGER_H
