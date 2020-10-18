#pragma once

#include "Cappuccino.hpp"

class DoubleCappuccino : public Cappuccino
{
public:
    DoubleCappuccino() : Cappuccino("Double Cappuccino") {}

    double GetCost() const override
    {
        return 120;
    }
};
