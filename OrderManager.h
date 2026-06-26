#pragma once
#include "Order.h"
#include <vector>

class OrderManager {
private:
    std::vector<Order> orders;
    int nextOrderId;

public:
    OrderManager();
    void addOrder(const Order& order);
    std::vector<Order> getAllOrders() const;
    int getNextOrderId();
    void viewAllOrders() const;
};
