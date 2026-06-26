#pragma once
#include "PaymentMethod.h"
#include <string>

class CreditCardPayment : public PaymentMethod {
private:
    std::string cardNumber;
    std::string expiryDate;
    std::string cvv;

public:
    CreditCardPayment(std::string cardNum, std::string exp, std::string cvvCode);

    bool processPayment(double amount) const override;
    std::string getMethodName() const override;
};
