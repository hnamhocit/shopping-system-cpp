#include "CheckoutSession.h"
#include "Address.h"
#include "Customer.h"
#include "ShippingMethod.h"
#include "CreditCardPayment.h"
#include "PayPalPayment.h"
#include "PaymentProcessor.h"
#include "Invoice.h"
#include <iostream>
#include <memory>
#include <limits>

bool CheckoutSession::start(std::vector<CartItem>& cartItems, OrderManager& orderManager) {
    if (cartItems.empty()) {
        std::cout << "Cart is empty. Cannot proceed to checkout.\n";
        return false;
    }

    std::cout << "\n--- Checkout Process ---\n";

    // Step 1: Calculate Cart Total
    double cartTotal = 0;
    for (const auto& item : cartItems) {
        cartTotal += item.getTotalPrice();
    }
    std::cout << "Cart Total: $" << cartTotal << "\n";

    // Step 2: Get Customer Information
    std::string name, email, phone, street, city, state, zip;
    std::cout << "\n[Step 1] Customer Information:\n";
    std::cout << "Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);

    std::cout << "\n[Step 2] Shipping Address:\n";
    std::cout << "Street: ";
    std::getline(std::cin, street);
    std::cout << "City: ";
    std::getline(std::cin, city);
    std::cout << "State: ";
    std::getline(std::cin, state);
    std::cout << "Zip Code: ";
    std::getline(std::cin, zip);

    Address address(street, city, state, zip);
    Customer customer(name, email, phone, address);

    // Step 3: Select Shipping Method
    std::cout << "\n[Step 3] Select Shipping Method:\n";
    std::cout << "1. Standard ($5.0, 3-5 days)\n";
    std::cout << "2. Express ($15.0, 1-2 days)\n";
    std::cout << "Choose (1-2): ";
    int shipChoice;
    std::cin >> shipChoice;
    
    ShippingMethod shipping;
    if (shipChoice == 2) {
        shipping = ShippingMethod("Express", 15.0, 2);
    } else {
        shipping = ShippingMethod("Standard", 5.0, 5);
    }

    double finalTotal = cartTotal + shipping.getCost();
    std::cout << "Final Total to pay (incl. shipping): $" << finalTotal << "\n";

    // Step 4: Select Payment Method
    std::cout << "\n[Step 4] Select Payment Method:\n";
    std::cout << "1. Credit Card\n";
    std::cout << "2. PayPal\n";
    std::cout << "Choose (1-2): ";
    int payChoice;
    std::cin >> payChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::unique_ptr<PaymentMethod> paymentMethod;
    if (payChoice == 1) {
        std::string ccNum, exp, cvv;
        std::cout << "Card Number: ";
        std::getline(std::cin, ccNum);
        std::cout << "Expiry Date (MM/YY): ";
        std::getline(std::cin, exp);
        std::cout << "CVV: ";
        std::getline(std::cin, cvv);
        paymentMethod = std::make_unique<CreditCardPayment>(ccNum, exp, cvv);
    } else {
        std::string ppEmail;
        std::cout << "PayPal Email: ";
        std::getline(std::cin, ppEmail);
        paymentMethod = std::make_unique<PayPalPayment>(ppEmail);
    }

    // Step 5: Process Payment
    PaymentProcessor processor;
    bool paymentSuccess = processor.process(*paymentMethod, finalTotal);

    if (paymentSuccess) {
        // Step 6: Create Order
        std::vector<OrderItem> orderItems;
        for (const auto& cartItem : cartItems) {
            orderItems.push_back(OrderItem(
                cartItem.getProduct()->getId(),
                cartItem.getProduct()->getName(),
                cartItem.getProduct()->getPrice(),
                cartItem.getQuantity()
            ));
        }

        Order newOrder(orderManager.getNextOrderId(), customer, orderItems, shipping, finalTotal);
        orderManager.addOrder(newOrder);

        std::cout << "\nPayment successful! Order #" << newOrder.getOrderId() << " placed.\n";
        
        // Print Invoice
        Invoice::generateInvoice(newOrder);
        return true; // Indicates checkout was successful, caller should clear cart
    } else {
        std::cout << "\nCheckout failed.\n";
        return false;
    }
}
