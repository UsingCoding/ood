#pragma once

#include "../Duck/Duck.hpp"

class ReadHeadDuck: public Duck
{
public:
    ReadHeadDuck(std::function<void(void)> && flyBehavior);
    void Display() const override;
};
