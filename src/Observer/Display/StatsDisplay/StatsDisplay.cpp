#include "StatsDisplay.hpp"

void PrintAverageCounterMeasurement(const std::string && name, const AverageCounter & counter)
{
    std::cout << "Max " << name << " " << counter.GetMin() << std::endl;
    std::cout << "Min " << name << " " << counter.GetMax() << std::endl;
    std::cout << "Average " << name << " " << counter.GetMax() << std::endl;
    std::cout << "----------------" << std::endl;
}

void PrintAverageWindDirectionMeterMeasurement(const AverageWindDirectionMeter & windDirectionMeter)
{
    std::cout << "Average wind direction " << windDirectionMeter.GetAverage() << std::endl;
    std::cout << "----------------" << std::endl;
}

void StatsDisplay::Update(const WeatherInfo & data)
{
    m_temperature.AddIndex(data.m_temperature);
    m_humidity.AddIndex(data.m_humidity);
    m_pressure.AddIndex(data.m_pressure);
    m_windSpeed.AddIndex(data.m_windSpeed);
    m_windDirectionMeter.AddIndex(data.m_windSpeed, data.m_windDirection);

    std::cout << (data.m_source == WeatherDataSource::IN ? "Inter sensor" : "Outer sensor") << std::endl;

    PrintAverageCounterMeasurement("Temp", m_temperature);
    PrintAverageCounterMeasurement("Humidity", m_humidity);
    PrintAverageCounterMeasurement("Pressure", m_pressure);
    PrintAverageCounterMeasurement("Wind speed", m_windSpeed);
    PrintAverageWindDirectionMeterMeasurement(m_windDirectionMeter);
}
