//
// Created by supernotuser on 14.09.2020.
//

#include "WeatherData.hpp"

WeatherInfo WeatherData::GetChangedData() const
{
    return WeatherInfo{GetTemperature(), GetHumidity(), GetPressure()};
}
