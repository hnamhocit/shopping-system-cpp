#pragma once
#include <string>

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    
    // Process payment and return true if successful
    virtual bool processPayment(double amount) const = 0;
    virtual std::string getMethodName() const = 0;
};
