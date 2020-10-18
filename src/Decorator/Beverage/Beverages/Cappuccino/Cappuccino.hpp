#pragma once

#include "../Coffee/Coffee.hpp"

class Cappuccino : public Coffee
{
public:
    Cappuccino() : Coffee("Cappuccino")
    {}

    Cappuccino(std::string && description) : Coffee(description) {}

    double GetCost() const override
    {
        return 80;
    }
};

