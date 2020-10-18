#pragma once

#include "IBeverage.hpp"

class Beverage : public IBeverage
{
public:
    Beverage(const std::string & description)
            :m_description(description)
    {}

    std::string GetDescription() const override final
    {
        return m_description;
    }

private:
    std::string m_description;
};
