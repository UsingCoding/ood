#pragma once

#include "Condiments.hpp"

class Liquor : public CondimentDecorator
{
public:
    Liquor(IBeveragePtr && beverage): CondimentDecorator(move(beverage)) {}

    double GetCondimentCost() const override
    {
        return 50;
    }
};
