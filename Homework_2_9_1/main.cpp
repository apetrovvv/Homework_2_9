#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    bool operator==(const Fraction &other) const
    {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }
    bool operator!=(const Fraction &other) const
    {
        return numerator_ != other.numerator_ || denominator_ != other.denominator_;
    }
    bool operator>(const Fraction &other) const
    {
        if (denominator_ != other.denominator_)
            return numerator_ < other.numerator_;
        else
            return denominator_ > other.denominator_;
    }
    bool operator<(const Fraction &other) const
    {
        if (denominator_ != other.denominator_)
            return numerator_ > other.numerator_;
        else
            return denominator_ < other.denominator_;
    }
    bool operator >= (const Fraction &other) const
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
    bool operator <= (const Fraction &other) const
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
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}