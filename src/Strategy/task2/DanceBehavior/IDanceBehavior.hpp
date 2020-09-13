#pragma once

class IDanceBehavior
{
public:
    virtual void Dance(int speed) = 0;
    virtual ~IDanceBehavior() {}
};
