#include "PhysicalProduct.h"
#include <iostream>

PhysicalProduct::PhysicalProduct(int id, const std::string &name, double price,
                                 const Category &category, double weight,
                                 double shippingFee)
    : Product(id, name, price, category), weight(weight),
      shippingFee(shippingFee) {}

double PhysicalProduct::getShippingFee() const {
  return shippingFee + weight * 10;
}

std::string PhysicalProduct::getType() const { return "Physical Product"; }

void PhysicalProduct::display() const {
  std::cout << "ID: " << getId() << " | Name: " << getName()
            << " | Price: " << getPrice()
            << " | Category: " << getCategory().getName()
            << " | Weight: " << weight << " | Shipping Fee: " << shippingFee
            << std::endl;
}
