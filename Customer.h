#pragma once
#include <string>
#include "Address.h"

class Customer {
private:
    std::string name;
    std::string email;
    std::string phone;
    Address shippingAddress;

public:
    Customer(const std::string& name, const std::string& email, const std::string& phone, const Address& address);
    Customer();

    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
    Address getShippingAddress() const;
};
