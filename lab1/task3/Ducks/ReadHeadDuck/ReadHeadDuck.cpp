#include "ReadHeadDuck.hpp"
#include <iostream>

ReadHeadDuck::ReadHeadDuck(): Duck(
    [](){ std::cout << "Flying with wings" << std::endl; },
    [](){ std::cout << "Dancing minuet" << std::endl; }
)
{
}
