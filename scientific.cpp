#include <iostream>
#include "scientific.h"

/// Constructor
Scientific::Scientific() : Calculator() {}

/// Overrided welcome message to show scientific options
void Scientific::welcome() const
{
    std::cout << "\n\nEnter one of:\n"
    << "Basics: +, -, /, *, sqrt, square, log, ln, abs, pow\nTrigonometrie: sin, cos, tan, sec, csc, cot\nSystem: change, setmem, printmem\n"
    << "or exit\n";
}

/// Overridded parse operation to call correct member function
void Scientific::parseOperation(const std::string& input)
{
    /// Reuse code for all simple calc inputs
    /// If no simple calc match found it will continue below
    Calculator::parseOperation(input);

    if (input == "sin")
    {
        sin();
    }
    else if (input == "cos")
    {
        cos();
    }
    else if (input == "cot")
    {
        cot();
    }
    else if (input == "csc")
    {
        csc();
    }
    else if (input == "sec")
    {
        sec();
    }
    else if (input == "tan")
    {
        tan();
    }
    else if (input == "ln")
    {
        ln();
    }
    else if (input == "log")
    {
        log();
    }
    else if (input == "abs")
    {
        abs();
    }
    else if (input == "pow")
    {
        pow();
    }
}
void Scientific::sin()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::sin(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::cot()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = 1/std::tan(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::csc()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = 1/std::sin(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::sec()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = 1/std::cos(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::cos()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::cos(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::tan()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::tan(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::ln()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::log(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::log()
{
    std::string a, b;
    std::cout << "Enter the base: ";
    std::cin >> a;
    std::cout << "Enter a number: ";
    std::cin >> b;
    result = std::log(parseInput(b))/std::log(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::abs()
{
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::abs(parseInput(a));
    std::cout << "The result is " << result;
}
void Scientific::pow()
{
    std::string a, b;
    std::cout << "Enter the base: ";
    std::cin >> a;
    std::cout << "Enter the exponent: ";
    std::cin >> b;
    result = std::pow(parseInput(a), parseInput(b));
    std::cout << "The result is " << result;
}
