#include "MallardDuck.hpp"
#include "../../DanceBehavior/DanceBehavior.hpp"
#include "../../FlyBehavior/FlyBehavior.hpp"
#include <iostream>

MallardDuck::MallardDuck()
    : Duck(
        std::move(FlyBehavior::GetFlyBehavior()),
        std::move(DanceBehavior::GetDanceWaltzBehavior())
    )
{
}

void MallardDuck::Display() const
{
    std::cout << "I'm mallard duck" << std::endl;
}
