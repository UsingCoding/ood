#include "MallardDuck.hpp"
#include <memory>

#include "../../DanceBehavior/DanceWaltz/DanceWaltz.hpp"
#include "../../FlyBehavior/FlyWithWings/FlyWithWings.hpp"

MallardDuck::MallardDuck(): Duck(std::make_unique<FlyWithWings>(), std::make_unique<DanceWaltz>())
{
}
