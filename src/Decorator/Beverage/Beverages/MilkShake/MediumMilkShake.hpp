#pragma once

#include "MilkShake.hpp"

class MediumMilkShake : public MilkShake
{
    MediumMilkShake() : MilkShake("MediumMilkShake") {}

    double GetCost() const override
    {
        return 60;
    }
};
