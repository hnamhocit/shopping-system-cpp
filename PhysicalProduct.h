#pragma once

#include "Product.h"
#include <string>

class PhysicalProduct : public Product {
private:
  double weight;
  double shippingFee;

public:
  PhysicalProduct(int id, const std::string &name, double price,
                  const Category &category, double weight, double shippingFee);
  double getShippingFee() const override;
  std::string getType() const override;
  void display() const override;
};