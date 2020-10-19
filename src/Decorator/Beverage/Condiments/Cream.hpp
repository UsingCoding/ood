#pragma once

#include "Condiments.hpp"

class Cream : public CondimentDecorator
{
public:
    Cream(IBeveragePtr && beverage): CondimentDecorator(move(beverage)) {}

    std::string GetCondimentDescription() const override
    {
        return "Cream";
    }

    double GetCondimentCost() const override
    {
        return 25;
    }
};
