#include "Product.h"

Product::Product(int id, const std::string &name, double price,
                 const Category &category)
    : id(id), name(name), price(price), category(category) {}

int Product::getId() const { return id; }

std::string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

const Category &Product::getCategory() const { return category; }
