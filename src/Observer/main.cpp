#include "WeatherData/WeatherData.hpp"
#include "Display/Display/Display.hpp"
#include "Display/StatsDisplay/StatsDisplay.hpp"
#include "Display/ExpensiveDisplay/ExpensiveDisplay.hpp"

int main()
{

    WeatherData weatherDataIn(WeatherDataSource::IN);
    WeatherData weatherDataOut(WeatherDataSource::OUT);

    Display display;
    StatsDisplay statsDisplay;
    ExpensiveDisplay expensiveDisplay(weatherDataIn);

    weatherDataIn.RegisterObserver(EventType::TEMPERATURE_CHANGED, display);
    weatherDataIn.RegisterObserver(EventType::PRESSURE_CHANGED, display);

    weatherDataIn.RegisterObserver(EventType::TEMPERATURE_CHANGED, statsDisplay);
    weatherDataIn.RegisterObserver(EventType::HUMIDITY_CHANGED, statsDisplay);
    weatherDataIn.RegisterObserver(EventType::PRESSURE_CHANGED, statsDisplay);
    weatherDataIn.RegisterObserver(EventType::WIND_SPEED_CHANGED, statsDisplay);
    weatherDataIn.RegisterObserver(EventType::WIND_DIRECTION_CHANGED, statsDisplay);

    weatherDataIn.RegisterObserver(EventType::TEMPERATURE_CHANGED, expensiveDisplay, 10);

    weatherDataIn.SetMeasurements(40, 20, 0, 0, 90);

    weatherDataIn.RemoveObserver(EventType::TEMPERATURE_CHANGED, display);

    return 0;
}