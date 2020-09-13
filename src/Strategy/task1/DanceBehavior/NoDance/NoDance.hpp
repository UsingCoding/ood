#pragma once
#include "../IDanceBehavior.hpp"

class NoDance: public IDanceBehavior
{
public:
    NoDance();
    void Dance(int speed) override;
    ~NoDance();
};
