#pragma once

#include <string>

class Category {
private:
  int id;
  std::string name;

public:
  Category(int id, const std::string &name);
  int getId() const;
  std::string getName() const;
};