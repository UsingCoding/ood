#pragma once

#include "../../Beverage/Beverage.hpp"

class MilkShake : public Beverage
{
public:
    MilkShake() : Beverage("MilkShake")
    {}

    MilkShake(std::string && description) : Beverage(description) {}

    double GetCost() const override
    {
        return 80;
    }
};