#pragma once
#include "../IDanceBehavior.hpp"

class NoDance: public IDanceBehavior
{
public:
    NoDance();
    void dance() override;
    ~NoDance();
};
