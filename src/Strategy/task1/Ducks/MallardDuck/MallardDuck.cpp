#include "MallardDuck.hpp"
#include <memory>
#include <iostream>

#include "../../DanceBehavior/DanceWaltz/DanceWaltz.hpp"
#include "../../FlyBehavior/FlyWithWings/FlyWithWings.hpp"

MallardDuck::MallardDuck(): Duck(std::make_unique<FlyWithWings>(), std::make_unique<DanceWaltz>())
{
}

void MallardDuck::Display() const
{
    std::cout << "I'm mallard duck" << std::endl;
}
