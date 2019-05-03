#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <array>
#include <cmath>

class Calculator
{
public:
    Calculator();           /// Constructor
    virtual ~Calculator() = default;    /// Virtual destructor to prevent delete errors
    void add();             /// Functions to get user input and do operation
    void subtract();
    void multiply();
    void divide();
    void square();
    void sqrt();
    void setMem();          /// Functions to get and set mem
    void printMem() const;

    /// Parse input subs in number value when strings result or mem are entered
    double parseInput(const std::string&) const;

    /// provides data on user options, will be overloaded
    virtual void welcome() const;

    /// parse input and decide which member func to call
    virtual void parseOperation(const std::string&);

/// protected so derived class can access.
protected:
    double result;      /// data member to store result
    double mem;         /// data member to store mem
};

#endif // CALCULATOR_H
