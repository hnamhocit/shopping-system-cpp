#pragma once

#include "Product.h"
#include <string>

class DigitalProduct : public Product {
private:
  std::string downloadLink;

public:
  DigitalProduct(int id, std::string name, double price,
                 Category category, std::string downloadLink);
  double getShippingFee() const override;
  std::string getType() const override;
  void display() const override;
};
