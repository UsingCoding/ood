#pragma once

#include "../Observer/CObserverable.hpp"
#include "../MemoryIndex/MemoryIndex.hpp"

enum WeatherDataSource
{
    IN, OUT
};

enum EventType
{
    TEMPERATURE_CHANGED,
    HUMIDITY_CHANGED,
    PRESSURE_CHANGED,
    WIND_SPEED_CHANGED,
    WIND_DIRECTION_CHANGED
};

struct WeatherInfo
{
    WeatherDataSource m_source;
    EventType m_eventType;
    double m_measurement;
};

class WeatherData: public CObservable<WeatherInfo, EventType>
{
public:
    WeatherData(WeatherDataSource type);

    double GetTemperature() const
    {
        return m_temperature;
    }

    double GetHumidity() const
    {
        return m_humidity;
    }

    double GetPressure() const
    {
        return m_pressure;
    }

    double GetWindSpeed() const
    {
        return m_windSpeed;
    }

    double GetWindDirection() const
    {
        return m_windDirection;
    }

    void MeasurementsChanged()
    {
        NotifyObservers();
    }

    void SetMeasurements(double temp, double humidity, double pressure, double windSpeed, double windDirection)
    {
        std::map<EventType, double> changedMeasurementsMap;

        m_humidity.SetIndex(humidity);
        m_temperature.SetIndex(temp);
        m_pressure.SetIndex(pressure);
        m_windSpeed.SetIndex(windSpeed);
        m_windDirection.SetIndex(windDirection);

        MeasurementsChanged();
    }

protected:
    std::map<EventType, WeatherInfo> GetChangedData() const override;

private:
    WeatherDataSource m_type;
    MemoryIndex<double> m_temperature = 0.0;
    MemoryIndex<double> m_humidity = 0.0;
    MemoryIndex<double> m_pressure = 760.0;
    MemoryIndex<double> m_windSpeed = 3;
    MemoryIndex<double> m_windDirection = 0;
};
