#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;
    int gcd(int a, int b);

public:
    friend std::ostream& operator<<(std::ostream& stream, const Fraction& f);
    Fraction(int numerator, int denominator);
    bool operator == (const Fraction &other) const;
    bool operator != (const Fraction &other) const;
    bool operator > (const Fraction &other) const;
    bool operator < (const Fraction &other) const;
    bool operator >= (const Fraction &other) const;
    bool operator <= (const Fraction &other) const;
    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
};

