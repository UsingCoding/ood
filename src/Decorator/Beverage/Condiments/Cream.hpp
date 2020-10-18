#pragma once

#include "Condiments.hpp"

class Cream : public CondimentDecorator
{
public:
    std::string GetCondimentDescription() const override
    {
        return "Cream";
    }

    double GetCondimentCost() const override
    {
        return 25;
    }
};
