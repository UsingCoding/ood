#include "ReadHeadDuck.hpp"
#include "../../DanceBehavior/DanceBehavior.hpp"
#include "../../FlyBehavior/FlyBehavior.hpp"
#include <iostream>

ReadHeadDuck::ReadHeadDuck()
    : Duck(
        std::move(FlyBehavior::GetFlyBehavior()),
        std::move(DanceBehavior::GetDanceMinuetBehavior())
    )
{

}


void ReadHeadDuck::Display() const
{
    std::cout << "I'm redhead duck" << std::endl;
}
