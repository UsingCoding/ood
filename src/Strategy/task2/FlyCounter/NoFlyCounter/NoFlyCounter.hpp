#pragma once

#include "../IFlyCounter.hpp"

class NoFlyCounter: public IFlyCounter
{
    void Add() override;
};
