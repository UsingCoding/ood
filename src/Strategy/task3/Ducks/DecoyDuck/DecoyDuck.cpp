#include <iostream>
#include "DecoyDuck.hpp"

DecoyDuck::DecoyDuck(): Duck([](){}, [](int speed){})
{

}

void DecoyDuck::Display() const
{
    std::cout << "I'm decoy duck" << std::endl;
}
