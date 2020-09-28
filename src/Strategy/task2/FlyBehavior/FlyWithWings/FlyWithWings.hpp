#pragma once
#include "../IFlyBehavior.hpp"

class FlyWithWings: public IFlyBehavior
{
public:
    FlyWithWings();
    void Fly() override;
    ~FlyWithWings();

private:
    int m_flyCount;
};
