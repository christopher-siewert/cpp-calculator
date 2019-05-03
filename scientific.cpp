#include <iostream>
#include "scientific.h"

/// Constructor
Scientific::Scientific() : Calculator() {}

/// Overrided welcome message to show scientific options
void Scientific::welcome() const
{
    std::cout << "\n\nEnter one of:\n"
    << "+, -, /, *, sqrt, square, change, setmem, printmem, sin, cos, log, tan, ln, abs, pow\n"
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
    else if (input == "tan")
    {
        cos();
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
