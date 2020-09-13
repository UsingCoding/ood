#pragma once

class IFlyBehavior
{
public:
    virtual void fly() = 0;
    virtual ~IFlyBehavior() {}
};
