#pragma once

#include "../IFlyBehavior.hpp"

class NoFly: public IFlyBehavior
{
public:
    void Fly();
    ~NoFly();
};
