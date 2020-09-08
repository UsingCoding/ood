#pragma once

#include "../IDanceBehavior.hpp"

class MinuetDance: public IDanceBehavior
{
public:
    MinuetDance();
    void dance() override;
    ~MinuetDance();
};
