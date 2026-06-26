#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& email, const std::string& phone, const Address& address)
    : name(name), email(email), phone(phone), shippingAddress(address) {}

Customer::Customer() : name(""), email(""), phone(""), shippingAddress() {}

std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhone() const { return phone; }
Address Customer::getShippingAddress() const { return shippingAddress; }
