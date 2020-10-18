#pragma once

#include "../../Beverage/Beverage.hpp"

class Tea : public Beverage
{
public:
    Tea() : Beverage("Tea") {}

    double GetCost() const override
    {
        return 30;
    }
};