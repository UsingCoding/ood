#include "FlyCounter.hpp"
#include <iostream>

void FlyCounter::Add()
{
    ++m_count;
    std::cout << "Count: " << m_count << std::endl;
}
