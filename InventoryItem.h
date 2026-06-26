#pragma once

#include "Product.h"
#include <iostream>
#include <string>

class InventoryItem {
private:
  Product *product;
  int quantity;

public:
  InventoryItem(Product *product, int quantity);
  Product *getProduct() const;
  int getQuantity() const;
  bool isAvailable(int requestedQuantity) const;
  void decrease(int amount);
};
