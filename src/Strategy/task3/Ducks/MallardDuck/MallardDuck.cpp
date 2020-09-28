#include "MallardDuck.hpp"
#include <iostream>

MallardDuck::MallardDuck(std::function<void(void)> && flyBehavior): Duck(
        std::move(flyBehavior),
        [](int speed){ std::cout << "Dancing waltz with speed: " << speed << std::endl; }
)
{
}

void MallardDuck::Display() const
{
    std::cout << "I'm mallard duck" << std::endl;
}
