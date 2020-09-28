#include <iostream>
#include "DecoyDuck.hpp"
#include "../../FlyBehavior/FlyBehavior.hpp"
#include "../../DanceBehavior/DanceBehavior.hpp"

DecoyDuck::DecoyDuck()
    : Duck(
        std::move(FlyBehavior::GetNoFlyBehavior()),
        std::move(DanceBehavior::GetNoDanceBehavior())
    )
{

}

void DecoyDuck::Display() const
{
    std::cout << "I'm decoy duck" << std::endl;
}
