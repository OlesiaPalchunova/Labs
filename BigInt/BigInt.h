#include <cmath>
#include <string>
#include<iostream>

#ifndef TEST1_BIGINT_H
#define TEST1_BIGINT_H


class BigInt{
    std::string digits;
public:

    BigInt();
    BigInt(std::string);
    BigInt(int);
    BigInt(BigInt &);
    ~BigInt() = default;

    BigInt& operator=(const BigInt&);
    BigInt& operator~();

    BigInt& operator++();
    BigInt operator++(int temp);
    BigInt& operator--();
    BigInt operator--(int temp);

    BigInt& operator+=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator/=(const BigInt&);

    friend bool operator==(const BigInt&, const BigInt&);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);

    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
    friend BigInt operator^(const BigInt &, const BigInt &);
    friend BigInt operator&(const BigInt &, const BigInt &);
    friend BigInt operator|(const BigInt &, const BigInt &);
    friend BigInt operator%(const BigInt &, const BigInt &);

    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);

    BigInt operator+();  // unary +
    BigInt operator-();  // unary -

    operator int() const;
    operator std::string() const;
    friend size_t size(const BigInt &);

    friend std::ostream &operator<<(std::ostream &,const BigInt &);
};



#endif //TEST1_BIGINT_H

#ifndef LAB1_BIGINT_H
#define LAB1_BIGINT_H

#endif //LAB1_BIGINT_H

