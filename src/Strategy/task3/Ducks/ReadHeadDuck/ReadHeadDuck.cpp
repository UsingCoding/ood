#include "ReadHeadDuck.hpp"
#include <iostream>

ReadHeadDuck::ReadHeadDuck(): Duck(
        [](){ std::cout << "Flying with wings" << std::endl; },
        [](int speed){ std::cout << "Dancing minuet with speed: " << speed << std::endl; },
        [](){}
)
{
}
