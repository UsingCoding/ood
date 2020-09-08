#pragma once
#include "../IFlyBehavior.hpp"

class FlyWithWings: public IFlyBehavior
{
public:
    FlyWithWings();
    void fly() override;
    ~FlyWithWings();
};
