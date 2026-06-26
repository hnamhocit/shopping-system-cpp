#include "Customer.h"

Customer::Customer(std::string name, std::string email, std::string phone, Address address)
    : name(name), email(email), phone(phone), shippingAddress(address) {}

Customer::Customer() : name(""), email(""), phone(""), shippingAddress() {}

std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhone() const { return phone; }
Address Customer::getShippingAddress() const { return shippingAddress; }
