#include "WeatherData.hpp"

WeatherData::WeatherData(WeatherDataSource type) : m_type(type) {}

std::map<EventType, WeatherInfo> WeatherData::GetChangedData() const
{
    std::map<EventType, WeatherInfo> changedMeasurements;

    if (m_humidity.IsChanged())
    {
        changedMeasurements.insert(std::make_pair<EventType, WeatherInfo>(EventType::HUMIDITY_CHANGED, WeatherInfo{m_type, m_humidity}));
    }

    if (m_temperature.IsChanged())
    {
        changedMeasurements.insert(std::make_pair<EventType, WeatherInfo>(EventType::TEMPERATURE_CHANGED, WeatherInfo{m_type, m_temperature}));
    }

    if (m_pressure.IsChanged())
    {
        changedMeasurements.insert(std::make_pair<EventType, WeatherInfo>(EventType::PRESSURE_CHANGED, WeatherInfo{m_type, m_pressure}));
    }

    if (m_windSpeed.IsChanged())
    {
        changedMeasurements.insert(std::make_pair<EventType, WeatherInfo>(EventType::WIND_SPEED_CHANGED, WeatherInfo{m_type, m_windSpeed}));
    }

    if (m_windDirection.IsChanged())
    {
        changedMeasurements.insert(std::make_pair<EventType, WeatherInfo>(EventType::WIND_DIRECTION_CHANGED, WeatherInfo{m_type, m_windDirection}));
    }

    return changedMeasurements;
}
