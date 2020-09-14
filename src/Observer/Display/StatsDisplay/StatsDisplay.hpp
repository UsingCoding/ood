#pragma once

#include <iostream>
#include "../../Observer/IObserver.hpp"
#include "../../WeatherData/WeatherData.hpp"
#include "../../Sensor/AverageSensor.hpp"

class StatsDisplay: public IObserver<WeatherInfo>
{
private:
    void Update(const WeatherInfo & data) override;

    AverageSensor temperature;
    AverageSensor humidity;
    AverageSensor pressure;
};
