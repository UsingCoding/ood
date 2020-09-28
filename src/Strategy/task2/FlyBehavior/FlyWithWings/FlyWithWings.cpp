#include "FlyWithWings.hpp"
#include <iostream>

FlyWithWings::FlyWithWings()
{

}

void FlyWithWings::Fly()
{
    ++m_flyCount;
    std::cout << "Fly number: " << m_flyCount << std::endl;
    std::cout << "I`m flying with wings" << std::endl;
}

FlyWithWings::~FlyWithWings()
{

}
