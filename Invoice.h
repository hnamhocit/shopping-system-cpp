#pragma once
#include "Order.h"

class Invoice {
public:
    static void generateInvoice(const Order& order);
};
