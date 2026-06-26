#include "Product.h"
#include <string>

class DigitalProduct : public Product {
private:
  std::string downloadLink;

public:
  DigitalProduct(int id, const std::string &name, double price,
                 const Category &category, const std::string &downloadLink);
  double getShippingFee() const override;
  std::string getType() const override;
  void display() const override;
};
