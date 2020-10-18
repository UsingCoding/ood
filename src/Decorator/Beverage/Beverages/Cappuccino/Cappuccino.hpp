#pragma once

#include "../Coffee/Coffee.hpp"

class Cappuccino : public Coffee
{
public:
    Cappuccino() : Coffee("Cappuccino")
    {}

    double GetCost() const override
    {
        return 80;
    }
};

