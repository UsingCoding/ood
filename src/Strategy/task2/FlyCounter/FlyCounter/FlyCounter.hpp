#pragma once

#include "../IFlyCounter.hpp"

class FlyCounter: public IFlyCounter
{
private:
    int m_count = 0;

    void Add() override;
};
