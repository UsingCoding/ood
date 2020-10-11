#include "WeatherData/WeatherData.hpp"
#include "Display/Display/Display.hpp"
#include "Display/StatsDisplay/StatsDisplay.hpp"
#include "Display/ExpensiveDisplay/ExpensiveDisplay.hpp"

int main()
{
#if 0
    WeatherData weatherDataIn(WeatherDataSource::IN);
    WeatherData weatherDataOut(WeatherDataSource::OUT);

    Display display;
    StatsDisplay statsDisplay;
    ExpensiveDisplay expensiveDisplay(weatherDataIn);

    weatherDataIn.RegisterObserver(1, display);
    weatherDataIn.RegisterObserver(2, statsDisplay);
    weatherDataIn.RegisterObserver(0, expensiveDisplay);

    weatherDataIn.SetMeasurements(3, 0.7, 760);

    weatherDataIn.RemoveObserver(display);
    weatherDataIn.RemoveObserver(statsDisplay);
    weatherDataIn.SetMeasurements(5, 0.5, 767);
#endif

    WeatherData weatherDataIn(WeatherDataSource::IN);

    StatsDisplay statsDisplay;
    weatherDataIn.RegisterObserver(1, statsDisplay);

    weatherDataIn.SetMeasurements(5, 0.5, 767, 3, 40);

//    weatherDataIn.SetMeasurements(5, 0.5, 767, 2, 20);

    return 0;
}