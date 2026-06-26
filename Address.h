#pragma once
#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;

public:
    Address(std::string st, std::string c, std::string s, std::string z);
    Address(); // Default constructor

    std::string getStreet() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZipCode() const;

    std::string getFullAddress() const;
};
