#pragma once

#include "../IDanceBehavior.hpp"

class DanceWaltz: public IDanceBehavior
{
private:

public:
    DanceWaltz();
    void dance() override;
    ~DanceWaltz();
};
