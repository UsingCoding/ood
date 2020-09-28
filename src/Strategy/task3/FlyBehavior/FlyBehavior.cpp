#include "FlyBehavior.hpp"

FlyBehavior::FlyBehavior FlyBehavior::GetFlyBehavior()
{
    int flyCounter = 0;
    return [flyCounter]() mutable {
        ++flyCounter;
        std::cout << "Flying with wings, number: " << flyCounter << std::endl;
    };
}

FlyBehavior::FlyBehavior FlyBehavior::GetNoFlyBehavior()
{
    return []() {
        std::cout << "Not flying" << std::endl;
    };
}