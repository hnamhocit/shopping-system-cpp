#include "OrderItem.h"

OrderItem::OrderItem(int pId, const std::string& name, double price, int qty)
    : productId(pId), productName(name), priceAtPurchase(price), quantity(qty) {}

int OrderItem::getProductId() const { return productId; }
std::string OrderItem::getProductName() const { return productName; }
double OrderItem::getPriceAtPurchase() const { return priceAtPurchase; }
int OrderItem::getQuantity() const { return quantity; }
