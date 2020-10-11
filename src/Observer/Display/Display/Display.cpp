#include <iostream>
#include "Display.hpp"

void Display::Update(const WeatherInfo &data)
{
    std::cout << (data.m_source == WeatherDataSource::IN ? "Inter sensor" : "Outer sensor") << std::endl;
    std::cout << "Current " << data.m_changedMeasurement << std::endl;
//    std::cout << "Current Temp " << data.m_temperature << std::endl;
//    std::cout << "Current Hum " << data.m_humidity << std::endl;
//    std::cout << "Current Pressure " << data.m_pressure << std::endl;
    std::cout << "----------------" << std::endl;
}
