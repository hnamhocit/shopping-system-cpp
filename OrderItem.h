#pragma once
#include <string>

class OrderItem {
private:
    int productId;
    std::string productName;
    double priceAtPurchase;
    int quantity;

public:
    OrderItem(int pId, std::string name, double price, int qty);

    int getProductId() const;
    std::string getProductName() const;
    double getPriceAtPurchase() const;
    int getQuantity() const;
};
