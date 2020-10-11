#include <iostream>
#include "Display.hpp"

void Display::Update(const WeatherInfo &data)
{
    std::cout << (data.m_source == WeatherDataSource::IN ? "Inner sensor" : "Outer sensor") << std::endl;

    std::cout << "Current ";

    switch (data.m_eventType)
    {
        case TEMPERATURE_CHANGED:
            std::cout << "Temp ";
            break;
        case HUMIDITY_CHANGED:
            std::cout << "Hum ";
            break;
        case PRESSURE_CHANGED:
            std::cout << "Pressure ";
            break;
        case WIND_SPEED_CHANGED:
            std::cout << "Wind speed ";
            break;
        case WIND_DIRECTION_CHANGED:
            std::cout << "Wind direction ";
            break;
    }

    std::cout << data.m_measurement << std::endl;
    std::cout << "----------------" << std::endl;
}
