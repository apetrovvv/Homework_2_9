#include <iostream>
#include "fraction.h"

int main()
{
    int num1 = 1, den1 = 1, num2 = 1, den2 = 1;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;
    Fraction f1(num1, den1);
    Fraction f2(num2, den2);
    std::cout << f1 << " + " << f2 << " = " << f1+f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1-f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1*f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1/f2 << std::endl;
    Fraction pre_inc = ++f1;
    std::cout << "++" << f1 << " * " << f2 << " = " << pre_inc * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << pre_inc << std::endl;
    Fraction post_dec = pre_inc--;
    std::cout << post_dec << "--" << " * " << f2 << " = " << post_dec * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << pre_inc << std::endl;
    return 0;
}