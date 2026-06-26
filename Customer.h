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
    Customer(std::string name, std::string email, std::string phone, Address address);
    Customer();

    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
    Address getShippingAddress() const;
};
