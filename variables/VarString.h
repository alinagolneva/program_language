//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_VARSTRING_H
#define PROGRAM_LANGUAGE_VARSTRING_H


#include "Var.h"

class VarString final: public Var {
private:
    const std::string value;

public:
    explicit VarString(const std::string& value);

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


#endif //PROGRAM_LANGUAGE_VARSTRING_H
