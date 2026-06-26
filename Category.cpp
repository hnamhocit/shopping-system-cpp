#include "Category.h"
#include <string>

Category::Category(int id, const std::string &name) : id(id), name(name) {}

int Category::getId() const { return id; }

std::string Category::getName() const { return name; }
