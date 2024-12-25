#include "fraction.h"

int Fraction::gcd(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }

    while (b) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

Fraction::Fraction(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
}

bool Fraction::operator==(const Fraction &other) const
{
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Fraction::operator!=(const Fraction &other) const
{
    return numerator_ != other.numerator_ || denominator_ != other.denominator_;
}

bool Fraction::operator>(const Fraction &other) const
{
    if (denominator_ != other.denominator_)
        return numerator_ < other.numerator_;
    else
        return denominator_ > other.denominator_;
}

bool Fraction::operator<(const Fraction &other) const
{
    if (denominator_ != other.denominator_)
        return numerator_ > other.numerator_;
    else
        return denominator_ < other.denominator_;
}

bool Fraction::operator >= (const Fraction &other) const
{
    if (denominator_ != other.denominator_)
        return numerator_ < other.numerator_;
    else
    {
        if (numerator_ == other.numerator_)
            return true;
        return denominator_ > other.denominator_;
    }
}

bool Fraction::operator <= (const Fraction &other) const
{
    if (denominator_ != other.denominator_)
        return numerator_ > other.numerator_;
    else
    {
        if (numerator_ == other.numerator_)
            return true;
        return denominator_ < other.denominator_;
    }
}

Fraction Fraction::operator+ (const Fraction &other)
{
    int numerator = 0;
    if(denominator_ != other.denominator_){
        int denominator = denominator_ * other.denominator_;
        numerator = (numerator_ *  other.denominator_) + (other.numerator_ * denominator_);
        return Fraction(numerator, denominator);
    }
    numerator = numerator_ + other.numerator_;
    return Fraction(numerator, denominator_);
}

Fraction Fraction::operator- (const Fraction &other)
{
    int numerator = 0;
    if(denominator_ != other.denominator_){
        int denominator = denominator_ * other.denominator_;
        numerator = (numerator_ *  other.denominator_) - (other.numerator_ * denominator_);
        return Fraction(numerator, denominator);
    }
    numerator = numerator_ - other.numerator_;
    return Fraction(numerator, denominator_);
}

Fraction Fraction::operator* (const Fraction &other)
{
    int numerator = 0;
    int denominator = 0;
    numerator = numerator_ * other.numerator_;
    denominator = denominator_ * other.denominator_;
    int nod = gcd(numerator, denominator);
    return Fraction(numerator/nod, denominator/nod);
}

Fraction Fraction::operator/ (const Fraction &other)
{
    return *this * Fraction(other.denominator_, other.numerator_);
}

std::ostream &operator<<(std::ostream& stream, const Fraction& f)
{
    stream << f.numerator_;
    stream << "/";
    stream << f.denominator_;
    return stream;
}

Fraction Fraction::operator++()
{
    return *this + Fraction(1,1);
}

Fraction Fraction::operator--()
{
    return *this - Fraction(1,1);
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    *this = *this + Fraction(1,1);
    return temp;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    *this = *this - Fraction(1,1);
    return temp;
}