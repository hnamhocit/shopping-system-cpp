#pragma once

#include "Category.h"
#include <string>

class Product {
private:
  int id;
  std::string name;
  double price;
  Category category;

public:
  Product(int id, const std::string &name, double price,
          const Category &category);
  int getId() const;
  std::string getName() const;
  double getPrice() const;
  const Category &getCategory() const;

  virtual void display() const = 0;
  virtual double getShippingFee() const = 0;
  virtual std::string getType() const = 0;

  virtual ~Product() = default;
};