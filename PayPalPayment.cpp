#include "PayPalPayment.h"
#include <iostream>

PayPalPayment::PayPalPayment(std::string accountEmail) : email(accountEmail) {}

bool PayPalPayment::processPayment(double amount) const {
    std::cout << "Processing PayPal payment of $" << amount << " for account " << email << "...\n";
    // Simulate successful payment
    return true;
}

std::string PayPalPayment::getMethodName() const {
    return "PayPal";
}
