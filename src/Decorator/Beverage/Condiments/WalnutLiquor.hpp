#pragma once

#include "Liquor.hpp"

class WalnutLiquor : public Liquor
{
public:
    WalnutLiquor(IBeveragePtr && beverage): Liquor(move(beverage)) {}

    std::string GetCondimentDescription() const override
    {
        return "Walnut Liquor";
    }
};

