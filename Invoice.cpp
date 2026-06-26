#include "Invoice.h"
#include <iostream>

void Invoice::generateInvoice(const Order& order) {
    std::cout << "\n========================================\n";
    std::cout << "                INVOICE                 \n";
    std::cout << "========================================\n";
    std::cout << "Order ID: " << order.getOrderId() << "\n";
    std::cout << "Status:   " << order.getStatus() << "\n";
    std::cout << "----------------------------------------\n";
    
    Customer cust = order.getCustomer();
    std::cout << "Billed To:\n";
    std::cout << cust.getName() << "\n";
    std::cout << cust.getEmail() << " | " << cust.getPhone() << "\n";
    std::cout << cust.getShippingAddress().getFullAddress() << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Items:\n";
    
    for (const auto& item : order.getItems()) {
        std::cout << "- " << item.getProductName() << " (x" << item.getQuantity() << ") : $" 
                  << (item.getPriceAtPurchase() * item.getQuantity()) << "\n";
    }
    
    std::cout << "----------------------------------------\n";
    std::cout << "Shipping: " << order.getShippingMethod().getName() 
              << " ($" << order.getShippingMethod().getCost() << ")\n";
    std::cout << "Total Amount: $" << order.getTotalAmount() << "\n";
    std::cout << "========================================\n\n";
}
