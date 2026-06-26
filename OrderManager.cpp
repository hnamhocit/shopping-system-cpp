#include "OrderManager.h"
#include <iostream>

OrderManager::OrderManager() : nextOrderId(1001) {}

void OrderManager::addOrder(const Order& order) {
    orders.push_back(order);
}

std::vector<Order> OrderManager::getAllOrders() const {
    return orders;
}

int OrderManager::getNextOrderId() {
    return nextOrderId++;
}

void OrderManager::viewAllOrders() const {
    if (orders.empty()) {
        std::cout << "No orders found.\n";
        return;
    }
    std::cout << "\n--- Order History ---\n";
    for (const auto& order : orders) {
        std::cout << "Order ID: " << order.getOrderId() 
                  << " | Customer: " << order.getCustomer().getName() 
                  << " | Total: $" << order.getTotalAmount() 
                  << " | Status: " << order.getStatus() << "\n";
    }
}
