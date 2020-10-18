#pragma once

#include "Liquor.hpp"

class ChocolateLiquor : public Liquor
{
public:
    std::string GetCondimentDescription() const override
    {
        return "Chocolate Liquor";
    }
};
