#pragma once

#include "Condiments.hpp"

class Liquor : public CondimentDecorator
{
public:
    double GetCondimentCost() const override
    {
        return 50;
    }
};
