#include "StatsDisplay.hpp"

void PrintMeasurement(const std::string && name, const AverageSensor & sensor)
{
    std::cout << "Max " << name << " " << sensor.GetMin() << std::endl;
    std::cout << "Min " << name << " " << sensor.GetMax() << std::endl;
    std::cout << "Average " << name << " " << sensor.GetMax() << std::endl;
    std::cout << "----------------" << std::endl;
}

void StatsDisplay::Update(const WeatherInfo & data)
{
    temperature.AddIndex(data.temperature);
    humidity.AddIndex(data.humidity);
    pressure.AddIndex(data.pressure);

    PrintMeasurement("Temp", temperature);
    PrintMeasurement("Humidity", humidity);
    PrintMeasurement("Pressure", pressure);
}
