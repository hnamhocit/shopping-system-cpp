#pragma once
#include "PaymentMethod.h"
#include <string>

class PayPalPayment : public PaymentMethod {
private:
    std::string email;

public:
    PayPalPayment(const std::string& accountEmail);

    bool processPayment(double amount) const override;
    std::string getMethodName() const override;
};
