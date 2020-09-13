#pragma once

#include "../IDanceBehavior.hpp"

class MinuetDance: public IDanceBehavior
{
public:
    MinuetDance();
    void Dance(int speed) override;
    ~MinuetDance();
};
