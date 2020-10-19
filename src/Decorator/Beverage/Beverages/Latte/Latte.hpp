#pragma once

#include "../Coffee/Coffee.hpp"

class Latte : public Coffee
{
public:
    Latte() : Coffee("Latte")
    {}

    Latte(const std::string & description) : Coffee(description) {}

    double GetCost() const override
    {
        return 90;
    }
};
