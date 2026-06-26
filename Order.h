#pragma once
#include "Customer.h"
#include "OrderItem.h"
#include "ShippingMethod.h"
#include <vector>
#include <string>

class Order {
private:
    int orderId;
    Customer customer;
    std::vector<OrderItem> items;
    ShippingMethod shippingMethod;
    double totalAmount;
    std::string status;

public:
    Order(int id, Customer cust, std::vector<OrderItem> itemsList, ShippingMethod shipping, double total);

    int getOrderId() const;
    Customer getCustomer() const;
    std::vector<OrderItem> getItems() const;
    ShippingMethod getShippingMethod() const;
    double getTotalAmount() const;
    std::string getStatus() const;
    void setStatus(std::string newStatus);
};
