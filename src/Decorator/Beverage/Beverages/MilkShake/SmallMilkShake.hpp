#pragma once

#include "MilkShake.hpp"

class SmallMilkShake : public MilkShake
{
public:
    SmallMilkShake() : MilkShake("SmallMilkShake") {}

    double GetCost() const override
    {
        return 50;
    }
};

