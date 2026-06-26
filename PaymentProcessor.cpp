#include "PaymentProcessor.h"
#include <iostream>

bool PaymentProcessor::process(const PaymentMethod& paymentMethod, double amount) const {
    std::cout << "[PaymentProcessor] Connecting to gateway for " << paymentMethod.getMethodName() << "...\n";
    bool success = paymentMethod.processPayment(amount);
    if (success) {
        std::cout << "[PaymentProcessor] Payment of $" << amount << " approved.\n";
    } else {
        std::cout << "[PaymentProcessor] Payment failed.\n";
    }
    return success;
}
