cmake_minimum_required(VERSION 3.20)

project(ShoppingSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ShoppingSystem
    main.cpp

    Category.cpp
    Product.cpp
    PhysicalProduct.cpp
    DigitalProduct.cpp

    CartItem.cpp
    InventoryItem.cpp
    
    Address.cpp
    Customer.cpp
    ShippingMethod.cpp
    PaymentMethod.cpp
    CreditCardPayment.cpp
    PayPalPayment.cpp
    PaymentProcessor.cpp
    OrderItem.cpp
    Order.cpp
    OrderManager.cpp
    Invoice.cpp
    CheckoutSession.cpp

    ShoppingSystem.cpp
)