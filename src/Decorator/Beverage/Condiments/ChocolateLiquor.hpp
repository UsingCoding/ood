#pragma once

#include "Liquor.hpp"

class ChocolateLiquor : public Liquor
{
public:
    ChocolateLiquor(IBeveragePtr && beverage): Liquor(move(beverage)) {}

    std::string GetCondimentDescription() const override
    {
        return "Chocolate Liquor";
    }
};
