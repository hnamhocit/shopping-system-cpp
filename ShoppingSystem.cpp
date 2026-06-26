#include "ShoppingSystem.h"
#include "DigitalProduct.h"
#include "PhysicalProduct.h"
#include "CheckoutSession.h"
#include <memory>
#include <ostream>

ShoppingSystem::ShoppingSystem() { seedData(); }

void ShoppingSystem::seedData() {
  categories.push_back(Category(1, "Electronics"));
  categories.push_back(Category(2, "Books"));
  categories.push_back(Category(3, "Courses"));
  categories.push_back(Category(4, "Accessories"));

  products.push_back(std::make_unique<PhysicalProduct>(
      1, "Laptop", 1500.0, categories[0], 2.5, 25.0));
  inventory.push_back(InventoryItem(products.back().get(), 10));

  products.push_back(std::make_unique<PhysicalProduct>(
      2, "Mouse", 25.0, categories[3], 0.2, 5.0));
  inventory.push_back(InventoryItem(products.back().get(), 50));

  products.push_back(std::make_unique<PhysicalProduct>(
      3, "Keyboard", 45.0, categories[3], 0.8, 10.0));
  inventory.push_back(InventoryItem(products.back().get(), 30));

  products.push_back(std::make_unique<DigitalProduct>(
      4, "C++ E-book", 10.0, categories[1],
      "https://example.com/download/cpp-ebook"));

  products.push_back(std::make_unique<DigitalProduct>(
      5, "Online C++ Course", 50.0, categories[2],
      "https://example.com/course/cpp"));
}

void ShoppingSystem::showMenu() const {
  std::cout << "\n===== SHOPPING SYSTEM =====\n";
  std::cout << "1. View all products\n";
  std::cout << "2. View categories\n";
  std::cout << "3. View products by category\n";
  std::cout << "4. Add product to cart\n";
  std::cout << "5. View cart\n";
  std::cout << "6. Remove product from cart\n";
  std::cout << "7. Checkout\n";
  std::cout << "8. View Order History\n";
  std::cout << "0. Exit\n";
  std::cout << "Choose: ";
}

void ShoppingSystem::run() {
  int choice;

  do {
    showMenu();
    std::cin >> choice;

    switch (choice) {
    case 1:
      viewProducts();
      break;

    case 2:
      viewCategories();
      break;

    case 3:
      viewProductsByCategory();
      break;

    case 4:
      addProductToCart();
      break;

    case 5:
      viewCart();
      break;

    case 6:
      removeProductFromCart();
      break;

    case 7:
      checkout();
      break;

    case 8:
      viewOrders();
      break;

    case 0:
      std::cout << "Goodbye!\n";
      break;

    default:
      std::cout << "Invalid choice.\n";
      break;
    }

  } while (choice != 0);
}

void ShoppingSystem::viewProducts() const {
  std::cout << "\n===== PRODUCT LIST =====\n";

  for (const auto &product : products) {
    product->display();
    std::cout << "Type: " << product->getType() << '\n';
    std::cout << "Shipping Fee: " << product->getShippingFee() << '\n';
    std::cout << "------------------------\n";
  }
}

void ShoppingSystem::viewCategories() const {
  std::cout << "\n===== CATEGORIES =====\n";

  for (const Category &category : categories) {
    std::cout << category.getId() << ". " << category.getName() << '\n';
  }
}

void ShoppingSystem::viewProductsByCategory() const {
  int categoryId;

  viewCategories();

  std::cout << "Enter category id: ";
  std::cin >> categoryId;

  bool found = false;

  std::cout << "\n===== PRODUCTS BY CATEGORY =====\n";

  for (const auto &product : products) {
    if (product->getCategory().getId() == categoryId) {
      product->display();
      std::cout << "Type: " << product->getType() << '\n';
      std::cout << "------------------------\n";
      found = true;
    }
  }

  if (!found) {
    std::cout << "No products found in this category.\n";
  }
}

Product *ShoppingSystem::findProductById(int productId) const {
  for (const auto &product : products) {
    if (product->getId() == productId) {
      return product.get();
    }
  }

  return nullptr;
}

InventoryItem *ShoppingSystem::findInventoryItemByProductId(int productId) {
  for (InventoryItem &item : inventory) {
    if (item.getProduct()->getId() == productId) {
      return &item;
    }
  }

  return nullptr;
}

CartItem *ShoppingSystem::findCartItemByProductId(int productId) {
  for (CartItem &item : cartItems) {
    if (item.getProduct()->getId() == productId) {
      return &item;
    }
  }

  return nullptr;
}

void ShoppingSystem::addProductToCart() {
  int productId;
  int quantity;

  viewProducts();

  std::cout << "Enter product id: ";
  std::cin >> productId;

  std::cout << "Enter quantity: ";
  std::cin >> quantity;

  if (quantity <= 0) {
    std::cout << "Quantity must be greater than 0.\n";
    return;
  }

  Product *product = findProductById(productId);

  if (product == nullptr) {
    std::cout << "Product not found.\n";
    return;
  }

  CartItem *existingCartItem = findCartItemByProductId(productId);
  int currentQuantityInCart = 0;

  if (existingCartItem != nullptr) {
    currentQuantityInCart = existingCartItem->getQuantity();
  }

  int newTotalQuantity = currentQuantityInCart + quantity;

  if (product->getType() == "Physical") {
    InventoryItem *inventoryItem = findInventoryItemByProductId(productId);

    if (inventoryItem == nullptr) {
      std::cout << "Inventory not found.\n";
      return;
    }

    if (!inventoryItem->isAvailable(newTotalQuantity)) {
      std::cout << "Not enough stock.\n";
      std::cout << "Available stock: " << inventoryItem->getQuantity() << '\n';
      return;
    }
  }

  if (existingCartItem != nullptr) {
    existingCartItem->setQuantity(newTotalQuantity);
  } else {
    cartItems.push_back(CartItem(product, quantity));
  }

  std::cout << "Added to cart successfully.\n";
}

void ShoppingSystem::viewCart() const {
  if (cartItems.empty()) {
    std::cout << "\nYour cart is empty.\n";
    return;
  }

  double total = 0;

  std::cout << "\n===== YOUR CART =====\n";

  for (const CartItem &item : cartItems) {
    Product *product = item.getProduct();

    std::cout << "Product ID: " << product->getId() << '\n';
    std::cout << "Name: " << product->getName() << '\n';
    std::cout << "Type: " << product->getType() << '\n';
    std::cout << "Price: " << product->getPrice() << '\n';
    std::cout << "Quantity: " << item.getQuantity() << '\n';
    std::cout << "Subtotal: " << item.getTotalPrice() << '\n';
    std::cout << "------------------------\n";

    total += item.getTotalPrice();
  }

  std::cout << "Total: " << total << '\n';
}

void ShoppingSystem::removeProductFromCart() {
  if (cartItems.empty()) {
    std::cout << "Your cart is empty.\n";
    return;
  }

  int productId;

  viewCart();

  std::cout << "Enter product id to remove: ";
  std::cin >> productId;

  for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
    if (it->getProduct()->getId() == productId) {
      cartItems.erase(it);
      std::cout << "Removed from cart.\n";
      return;
    }
  }

  std::cout << "Product not found in cart.\n";
}

void ShoppingSystem::checkout() {
  if (CheckoutSession::start(cartItems, orderManager)) {
    cartItems.clear();
  }
}

void ShoppingSystem::viewOrders() const {
  orderManager.viewAllOrders();
}