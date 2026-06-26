#include "ShippingMethod.h"

ShippingMethod::ShippingMethod(std::string name, double cost, int estimatedDays)
    : name(name), cost(cost), estimatedDays(estimatedDays) {}

ShippingMethod::ShippingMethod() : name("Standard"), cost(0.0), estimatedDays(3) {}

std::string ShippingMethod::getName() const { return name; }
double ShippingMethod::getCost() const { return cost; }
int ShippingMethod::getEstimatedDays() const { return estimatedDays; }
