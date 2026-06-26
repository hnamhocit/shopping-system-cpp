#include "CreditCardPayment.h"
#include <iostream>

CreditCardPayment::CreditCardPayment(const std::string& cardNum, const std::string& exp, const std::string& cvvCode)
    : cardNumber(cardNum), expiryDate(exp), cvv(cvvCode) {}

bool CreditCardPayment::processPayment(double amount) const {
    std::cout << "Processing credit card payment of $" << amount << " via card ending in " 
              << cardNumber.substr(cardNumber.length() > 4 ? cardNumber.length() - 4 : 0) << "...\n";
    // Simulate successful payment
    return true;
}

std::string CreditCardPayment::getMethodName() const {
    return "Credit Card";
}
