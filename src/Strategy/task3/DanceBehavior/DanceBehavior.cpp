#include "DanceBehavior.hpp"

DanceBehavior::DanceBehavior DanceBehavior::GetDanceWaltzBehavior()
{
    return [](int speed) {
        std::cout << "Dancing waltz with speed: " << speed << std::endl;
    };
}

DanceBehavior::DanceBehavior DanceBehavior::GetDanceMinuetBehavior()
{
    return [](int speed) {
        std::cout << "Dancing minuet with speed: " << speed << std::endl;
    };
}

DanceBehavior::DanceBehavior DanceBehavior::GetNoDanceBehavior()
{
    return [](int speed) {
        std::cout << "Not dancing" << std::endl;
    };
}
