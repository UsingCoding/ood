#pragma once

#include "../Observer/CObserverable.hpp"

enum WeatherDataSource
{
    IN, OUT
};

enum EventType
{
    TEMPERATURE_CHANGED
};

struct WeatherInfo
{
    WeatherDataSource m_source;
    double m_temperature;
    double m_humidity;
    double m_pressure;
    double m_windSpeed;
    size_t m_windDirection;
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

    size_t GetWindDirection() const
    {
        return m_windDirection;
    }

    void MeasurementsChanged()
    {
        NotifyObservers();
    }

    void SetMeasurements(double temp, double humidity, double pressure, double windSpeed, size_t windDirection)
    {
        m_humidity = humidity;
        m_temperature = temp;
        m_pressure = pressure;
        m_windSpeed = windSpeed;
        m_windDirection = windDirection;

        MeasurementsChanged();
    }

protected:
    WeatherInfo GetChangedData() const override;

private:
    WeatherDataSource m_type;
    double m_temperature = 0.0;
    double m_humidity = 0.0;
    double m_pressure = 760.0;
    double m_windSpeed = 3;
    size_t m_windDirection = 270;
};
