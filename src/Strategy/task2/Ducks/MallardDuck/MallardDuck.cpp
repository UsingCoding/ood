#include "MallardDuck.hpp"
#include <memory>
#include <iostream>

#include "../../DanceBehavior/DanceWaltz/DanceWaltz.hpp"
#include "../../FlyBehavior/FlyWithWings/FlyWithWings.hpp"
#include "../../FlyCounter/FlyCounter/FlyCounter.hpp"

MallardDuck::MallardDuck(): Duck(std::make_unique<FlyWithWings>(), std::make_unique<DanceWaltz>(), std::make_unique<FlyCounter>())
{
}

void MallardDuck::Display() const
{
    std::cout << "I'm mallard duck" << std::endl;
}
