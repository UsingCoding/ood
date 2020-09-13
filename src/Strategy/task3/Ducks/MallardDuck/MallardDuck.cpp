#include "MallardDuck.hpp"
#include <iostream>

MallardDuck::MallardDuck(): Duck(
        [](){ std::cout << "Flying with wings" << std::endl; },
        [](int speed){ std::cout << "Dancing waltz with speed: " << speed << std::endl; },
        [](){}
)
{
}
