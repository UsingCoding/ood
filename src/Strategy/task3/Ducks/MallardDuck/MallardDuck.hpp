#pragma once

#include "../Duck/Duck.hpp"

class MallardDuck: public Duck
{
public:
    MallardDuck();
    void Display() const override;
};
