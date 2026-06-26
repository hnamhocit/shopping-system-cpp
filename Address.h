#pragma once
#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;

public:
    Address(const std::string& st, const std::string& c, const std::string& s, const std::string& z);
    Address(); // Default constructor

    std::string getStreet() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZipCode() const;

    std::string getFullAddress() const;
};
