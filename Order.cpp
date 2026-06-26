#include "Order.h"

Order::Order(int id, Customer cust, std::vector<OrderItem> itemsList, ShippingMethod shipping, double total)
    : orderId(id), customer(cust), items(itemsList), shippingMethod(shipping), totalAmount(total), status("Completed") {}

int Order::getOrderId() const { return orderId; }
Customer Order::getCustomer() const { return customer; }
std::vector<OrderItem> Order::getItems() const { return items; }
ShippingMethod Order::getShippingMethod() const { return shippingMethod; }
double Order::getTotalAmount() const { return totalAmount; }
std::string Order::getStatus() const { return status; }
void Order::setStatus(std::string newStatus) { status = newStatus; }
