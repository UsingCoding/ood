#pragma once

#include "Latte.hpp"

class DoubleLatte : public Latte
{
public:
    DoubleLatte() : Latte("Double Latte") {}

    double GetCost() const override
    {
        return 130;
    }
};
