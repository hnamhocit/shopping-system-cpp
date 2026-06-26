#pragma once

#include "Product.h"

class CartItem {
private:
  Product *product;
  int quantity;

public:
  CartItem(Product *product, int quantity);
  Product *getProduct() const;
  int getQuantity() const;
  void setQuantity(int quantity);
  double getTotalPrice() const;
};
