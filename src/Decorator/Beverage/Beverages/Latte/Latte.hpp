#pragma once

#include "../Coffee/Coffee.hpp"

class Latte : public Coffee
{
public:
    Latte() : Coffee("Latte")
    {}

    double GetCost() const override
    {
        return 90;
    }
};
