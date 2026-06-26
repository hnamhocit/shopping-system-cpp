#include "CartItem.h"

CartItem::CartItem(Product *product, int quantity)
    : product(product), quantity(quantity) {}

Product *CartItem::getProduct() const { return product; }

int CartItem::getQuantity() const { return quantity; }

double CartItem::getTotalPrice() const {
  return product->getPrice() * quantity;
}

void CartItem::setQuantity(int quantity) { this->quantity = quantity; }
