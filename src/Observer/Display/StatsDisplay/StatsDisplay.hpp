#pragma once

#include <iostream>
#include "../../Observer/IObserver.hpp"
#include "../../WeatherData/WeatherData.hpp"
#include "../../Counter/AverageCounter.hpp"
#include "../../Counter/AverageWindDirectionMeter.hpp"

class StatsDisplay: public IObserver<WeatherInfo>
{
private:
    void Update(const WeatherInfo & data) override;

    AverageCounter m_temperature;
    AverageCounter m_humidity;
    AverageCounter m_pressure;
    AverageCounter m_windSpeed;
    AverageWindDirectionMeter m_windDirectionMeter;
};
