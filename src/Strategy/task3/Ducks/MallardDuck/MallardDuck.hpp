#pragma once

#include "../Duck/Duck.hpp"

class MallardDuck: public Duck
{
public:
    MallardDuck(std::function<void(void)> && flyBehavior);
    void Display() const override;
};
