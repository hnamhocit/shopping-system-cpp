#include "Address.h"

Address::Address(const std::string& st, const std::string& c, const std::string& s, const std::string& z)
    : street(st), city(c), state(s), zipCode(z) {}

Address::Address() : street(""), city(""), state(""), zipCode("") {}

std::string Address::getStreet() const { return street; }
std::string Address::getCity() const { return city; }
std::string Address::getState() const { return state; }
std::string Address::getZipCode() const { return zipCode; }

std::string Address::getFullAddress() const {
    return street + ", " + city + ", " + state + " " + zipCode;
}
