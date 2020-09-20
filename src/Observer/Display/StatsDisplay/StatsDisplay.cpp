#include "StatsDisplay.hpp"

void PrintMeasurement(const std::string && name, const AverageCounter & counter)
{
    std::cout << "Max " << name << " " << counter.GetMin() << std::endl;
    std::cout << "Min " << name << " " << counter.GetMax() << std::endl;
    std::cout << "Average " << name << " " << counter.GetMax() << std::endl;
    std::cout << "----------------" << std::endl;
}

void StatsDisplay::Update(const WeatherInfo & data)
{
    m_temperature.AddIndex(data.m_temperature);
    m_humidity.AddIndex(data.m_humidity);
    m_pressure.AddIndex(data.m_pressure);

    std::cout << (data.m_source == WeatherDataSource::IN ? "Inter sensor" : "Outer sensor") << std::endl;

    PrintMeasurement("Temp", m_temperature);
    PrintMeasurement("Humidity", m_humidity);
    PrintMeasurement("Pressure", m_pressure);
}
