#pragma once
#include "CartItem.h"
#include "OrderManager.h"
#include <vector>

class CheckoutSession {
public:
    // Processes the checkout. If successful, returns true so the cart can be cleared.
    static bool start(std::vector<CartItem>& cartItems, OrderManager& orderManager);
};
