#pragma once

#include "../Duck/Duck.hpp"

class ReadHeadDuck: public Duck
{
public:
    ReadHeadDuck();

    void Display() const override;
};
