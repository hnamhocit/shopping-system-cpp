#pragma once
#include <string>

class ShippingMethod {
private:
    std::string name;
    double cost;
    int estimatedDays;

public:
    ShippingMethod(const std::string& name, double cost, int estimatedDays);
    ShippingMethod();

    std::string getName() const;
    double getCost() const;
    int getEstimatedDays() const;
};
