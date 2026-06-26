#include "DigitalProduct.h"
#include <iostream>

DigitalProduct::DigitalProduct(int id, const std::string &name, double price,
                               const Category &category,
                               const std::string &downloadLink)
    : Product(id, name, price, category), downloadLink(downloadLink) {}

double DigitalProduct::getShippingFee() const { return 0; }

std::string DigitalProduct::getType() const { return "Digital Product"; }

void DigitalProduct::display() const {
  std::cout << "ID: " << getId() << " | Name: " << getName()
            << " | Price: " << getPrice()
            << " | Category: " << getCategory().getName() << std::endl;
}
