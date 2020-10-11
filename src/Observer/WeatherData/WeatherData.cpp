#include "WeatherData.hpp"

WeatherData::WeatherData(WeatherDataSource type) : m_type(type) {}

WeatherInfo WeatherData::GetChangedData() const
{
    return WeatherInfo{
        m_type,
        GetTemperature(),
        GetHumidity(),
        GetPressure(),
        GetWindSpeed(),
        GetWindDirection()
    };
}
