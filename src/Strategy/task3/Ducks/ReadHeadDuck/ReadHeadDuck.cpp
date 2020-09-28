#include "ReadHeadDuck.hpp"
#include <iostream>

ReadHeadDuck::ReadHeadDuck(std::function<void(void)> && flyBehavior): Duck(
        std::move(flyBehavior),
        [](int speed){ std::cout << "Dancing minuet with speed: " << speed << std::endl; }
)
{

}


void ReadHeadDuck::Display() const
{
    std::cout << "I'm redhead duck" << std::endl;
}
