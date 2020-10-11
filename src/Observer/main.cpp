#include "WeatherData/WeatherData.hpp"
#include "Display/Display/Display.hpp"
#include "Display/StatsDisplay/StatsDisplay.hpp"
#include "Display/ExpensiveDisplay/ExpensiveDisplay.hpp"

int main()
{

    WeatherData weatherDataIn(WeatherDataSource::IN);
//    WeatherData weatherDataOut(WeatherDataSource::OUT);

    Display display;
//    StatsDisplay statsDisplay;
//    ExpensiveDisplay expensiveDisplay(weatherDataIn);

    weatherDataIn.RegisterObserver(EventType::TEMPERATURE_CHANGED, display);
    weatherDataIn.RegisterObserver(EventType::PRESSURE_CHANGED, display);
//    weatherDataIn.RegisterObserver(2, statsDisplay);
//    weatherDataIn.RegisterObserver(0, expensiveDisplay);
//
    weatherDataIn.SetMeasurements(40, 20, 0, 0, 90);

    weatherDataIn.RemoveObserver(EventType::TEMPERATURE_CHANGED, display);

    return 0;
}