#include "Order.h"

Order::Order(int id, const Customer& cust, const std::vector<OrderItem>& itemsList, const ShippingMethod& shipping, double total)
    : orderId(id), customer(cust), items(itemsList), shippingMethod(shipping), totalAmount(total), status("Completed") {}

int Order::getOrderId() const { return orderId; }
Customer Order::getCustomer() const { return customer; }
std::vector<OrderItem> Order::getItems() const { return items; }
ShippingMethod Order::getShippingMethod() const { return shippingMethod; }
double Order::getTotalAmount() const { return totalAmount; }
std::string Order::getStatus() const { return status; }
void Order::setStatus(const std::string& newStatus) { status = newStatus; }
