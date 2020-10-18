#pragma once

#include "Liquor.hpp"

class WalnutLiquor : public Liquor
{
public:
    std::string GetCondimentDescription() const override
    {
        return "Walnut Liquor";
    }
};

