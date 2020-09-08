#include "MallardDuck.hpp"
#include <iostream>


MallardDuck::MallardDuck(): Duck(
    [](){ std::cout << "Flying with wings" << std::endl; },
    [](){ std::cout << "Dancing waltz" << std::endl; }
)
{
}
