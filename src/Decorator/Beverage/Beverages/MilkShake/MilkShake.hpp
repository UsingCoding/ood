#pragma once

#include "../../Beverage/Beverage.hpp"

class Milkshake : public Beverage
{
public:
    Milkshake() : Beverage("Milkshake")
    {}

    double GetCost() const override
    {
        return 80;
    }
};