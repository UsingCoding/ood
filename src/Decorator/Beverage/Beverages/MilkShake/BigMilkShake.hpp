#pragma once

#include "MilkShake.hpp"

class BigMilkShake : public MilkShake
{
    BigMilkShake() : MilkShake("BigMilkShake") {}

    double GetCost() const override
    {
        return 80;
    }
};