#pragma once
#include "PaymentMethod.h"
#include <memory>

class PaymentProcessor {
public:
    // Takes a PaymentMethod and an amount, processes it.
    bool process(const PaymentMethod& paymentMethod, double amount) const;
};
