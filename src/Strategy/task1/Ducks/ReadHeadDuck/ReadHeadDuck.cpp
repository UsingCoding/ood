#include "ReadHeadDuck.hpp"
#include <memory>
#include <iostream>

#include "../../DanceBehavior/MinuetDance/MinuetDance.hpp"
#include "../../FlyBehavior/FlyWithWings/FlyWithWings.hpp"

ReadHeadDuck::ReadHeadDuck(): Duck(std::make_unique<FlyWithWings>(), std::make_unique<MinuetDance>())
{
}

void ReadHeadDuck::Display() const
{
    std::cout << "I'm readhead duck" << std::endl;
}
