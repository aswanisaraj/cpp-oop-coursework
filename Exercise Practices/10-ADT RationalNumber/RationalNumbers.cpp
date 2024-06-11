#include <iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    // Constructors
    RationalNumber(int num, int den = 1) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            cerr << "Error: Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }
    }

    RationalNumber(int num) : numerator(num), denominator(1) {}

    // Mutators
    void setNumerator(int num) { numerator = num; }
    void setDenominator(int den)
    {
        if (den == 0)
        {
            cerr << "Error: Denominator cannot be zero. Denominator unchanged." << endl;
            return;
        }
        denominator = den;
    }

    // Accessors
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Overloaded operators
    friend ostream &operator<<(ostream &os, const RationalNumber &rational);

    friend istream &operator>>(istream &is, RationalNumber &rational);

    friend RationalNumber operator+(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator-(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator*(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator/(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator<(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator==(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator-(const RationalNumber &rational);

    friend bool operator!(const RationalNumber &rational);
};

ostream &operator<<(ostream &os, const RationalNumber &rational)
{
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

istream &operator>>(istream &is, RationalNumber &rational)
{
    is >> rational.numerator;
    char slash;
    is >> slash;
    if (slash != '/')
    {
        is.setstate(ios_base::failbit);
        return is;
    }
    is >> rational.denominator;
    return is;
}

RationalNumber operator+(const RationalNumber &lhs, const RationalNumber &rhs)
{
    int num = lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator;
    int den = lhs.denominator * rhs.denominator;
    return RationalNumber(num, den);
}

RationalNumber operator-(const RationalNumber &lhs, const RationalNumber &rhs)
{
    int num = lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator;
    int den = lhs.denominator * rhs.denominator;
    return RationalNumber(num, den);
}

RationalNumber operator*(const RationalNumber &lhs, const RationalNumber &rhs)
{
    int num = lhs.numerator * rhs.numerator;
    int den = lhs.denominator * rhs.denominator;
    return RationalNumber(num, den);
}

RationalNumber operator/(const RationalNumber &lhs, const RationalNumber &rhs)
{
    int num = lhs.numerator * rhs.denominator;
    int den = lhs.denominator * rhs.numerator;
    return RationalNumber(num, den);
}

bool operator<(const RationalNumber &lhs, const RationalNumber &rhs)
{
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
}

bool operator==(const RationalNumber &lhs, const RationalNumber &rhs)
{
    return lhs.numerator * rhs.denominator == rhs.numerator * lhs.denominator;
}

RationalNumber operator-(const RationalNumber &rational)
{
    return RationalNumber(-rational.numerator, rational.denominator);
}

bool operator!(const RationalNumber &rational)
{
    return rational.numerator < 0;
}

int main()
{
    // Example usage
    RationalNumber r1(1, 2);
    RationalNumber r2(2, 3);
    RationalNumber r3 = r1 + r2;
    cout << "r1 + r2 = " << r3 << endl;

    RationalNumber r4(3, 4);
    RationalNumber r5 = r3 * r4;
    cout << "r3 * r4 = " << r5 << endl;

    cout << "Is r1 < r2: " << boolalpha << (r1 < r2) << endl;

    return 0;
}
