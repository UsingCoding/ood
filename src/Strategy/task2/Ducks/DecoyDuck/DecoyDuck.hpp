#pragma once

#include "../Duck/Duck.hpp"

class DecoyDuck: public Duck
{
public:
    DecoyDuck();
    void Display() const override;
};
