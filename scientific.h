#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H


#include <string>
#include <array>
#include <cmath>
#include "calculator.h"

class Scientific : public Calculator
{
public:
    Scientific();       /// Constructor
    virtual ~Scientific() = default; /// Virtual destructor to prevent delete errors
    virtual void welcome() const override;        /// Options message
    virtual void parseOperation(const std::string& input) override; /// Parse operation input and call correct member func
    /// Extra operations not in simple calc
    void sin();
    void cos();
    void tan();
    void ln();
    void log();
    void abs();
    void pow();
};

#endif // SCIENTIFIC_H
