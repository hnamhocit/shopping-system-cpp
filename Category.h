#pragma once

#include <string>

class Category {
private:
  int id;
  std::string name;

public:
  Category(int id, std::string name);
  int getId() const;
  std::string getName() const;
};