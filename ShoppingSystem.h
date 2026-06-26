#pragma once

#include "CartItem.h"
#include "Category.h"
#include "InventoryItem.h"
#include "Product.h"
#include "OrderManager.h"

#include <memory>
#include <vector>

class ShoppingSystem {
private:
  std::vector<Category> categories;
  std::vector<std::unique_ptr<Product>> products;
  std::vector<InventoryItem> inventory;
  std::vector<CartItem> cartItems;
  OrderManager orderManager;

  Product *findProductById(int productId) const;
  InventoryItem *findInventoryItemByProductId(int productId);
  CartItem *findCartItemByProductId(int productId);

  void seedData();
  void showMenu() const;

  void viewProducts() const;
  void viewCategories() const;
  void viewProductsByCategory() const;
  void addProductToCart();
  void viewCart() const;
  void removeProductFromCart();
  void checkout();
  void viewOrders() const;

public:
  ShoppingSystem();

  void run();
};