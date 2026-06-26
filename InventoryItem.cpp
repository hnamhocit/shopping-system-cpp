#include "InventoryItem.h"

InventoryItem::InventoryItem(Product *product, int quantity)
    : product(product), quantity(quantity) {}

int InventoryItem::getQuantity() const { return quantity; }

Product *InventoryItem::getProduct() const { return product; }

bool InventoryItem::isAvailable(int requestedQuantity) const {
  return requestedQuantity <= quantity;
}

void InventoryItem::decrease(int amount) { quantity -= amount; }