//
// Created by Alina on 21.05.2022.
//

#ifndef PROGRAM_LANGUAGE_VAR_H
#define PROGRAM_LANGUAGE_VAR_H


#include <string>
#include <map>

class Var {
public:
    enum VarType {
        BOOL_VAR,
        INTEGER_VAR,
        DOUBLE_VAR,
        STRING_VAR,
    };

    explicit Var(const VarType& type);
    virtual ~Var();

    virtual Var* operator + (const Var&) const;
    virtual Var* operator - (const Var&) const;
    virtual Var* operator * (const Var&) const;
    virtual Var* operator / (const Var&) const;

    Var* operator !  (          ) const;
    Var* operator <  (const Var&) const;
    Var* operator <= (const Var&) const;
    Var* operator >  (const Var&) const;
    Var* operator >= (const Var&) const;
    Var* operator == (const Var&) const;
    Var* operator != (const Var&) const;
    Var* operator && (const Var&) const;
    Var* operator || (const Var&) const;

    [[nodiscard]] virtual explicit operator bool            () const;
    [[nodiscard]] virtual explicit operator long long       () const;
    [[nodiscard]] virtual explicit operator long double     () const;
    [[nodiscard]] virtual explicit operator std::string     () const = 0;


    [[nodiscard]] VarType getType() const;

    [[nodiscard]] virtual Var* copy() const = 0;

private:
    const VarType type;

    [[nodiscard]] std::string getTypeName() const;


protected:
    typedef Var super;

};


#endif //PROGRAM_LANGUAGE_VAR_H
