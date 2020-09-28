#include <iostream>
#include <functional>

namespace DanceBehavior
{
    typedef std::function<void(int)> DanceBehavior;
    DanceBehavior GetDanceWaltzBehavior();
    DanceBehavior GetDanceMinuetBehavior();
    DanceBehavior GetNoDanceBehavior();
}