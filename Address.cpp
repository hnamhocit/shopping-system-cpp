#include "Address.h"

Address::Address(std::string st, std::string c, std::string s, std::string z)
    : street(st), city(c), state(s), zipCode(z) {}

Address::Address() : street(""), city(""), state(""), zipCode("") {}

std::string Address::getStreet() const { return street; }
std::string Address::getCity() const { return city; }
std::string Address::getState() const { return state; }
std::string Address::getZipCode() const { return zipCode; }

std::string Address::getFullAddress() const {
    return street + ", " + city + ", " + state + " " + zipCode;
}
