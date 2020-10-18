#pragma once

#include "Condiments.hpp"
#include "../../../Utils/Strings.hpp"

class Chocolate : public CondimentDecorator
{
public:
    Chocolate(IBeveragePtr && beverage, unsigned quantity = 1)
    : CondimentDecorator(std::move(beverage))
    {
        if (quantity > 5)
        {
            throw std::logic_error(Strings::Concatenator() << "Chocolate slices must be less than " << MAX_SLICE_COUNT);
        }

        m_quantity = quantity;
    }

    std::string GetCondimentDescription() const override
    {
        return Strings::Concatenator() << m_quantity << " chocolate slices";
    }

    double GetCondimentCost() const override
    {
        return 10 * m_quantity;
    }

private:
    unsigned m_quantity;

    static const int MAX_SLICE_COUNT = 5;
};
