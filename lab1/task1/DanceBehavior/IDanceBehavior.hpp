#pragma once

class IDanceBehavior
{
public:
    virtual void dance() = 0;
    virtual ~IDanceBehavior() {}
};
