#pragma once

#include "../../Beverage/Beverage.hpp"

class Tea : public Beverage
{
public:
    Tea() : Beverage("Tea") {}

    Tea(const std::string & description) : Beverage(description) {}

    double GetCost() const override
    {
        return 30;
    }
};