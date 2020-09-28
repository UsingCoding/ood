#include <functional>
#include <iostream>

namespace FlyBehavior
{
    typedef std::function<void(void)> FlyBehavior;
    FlyBehavior GetFlyBehavior();
    FlyBehavior GetNoFlyBehavior();
}