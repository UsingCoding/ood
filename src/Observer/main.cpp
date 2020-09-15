#include "WeatherData/WeatherData.hpp"
#include "Display/Display/Display.hpp"
#include "Display/StatsDisplay/StatsDisplay.hpp"

int main()
{
    WeatherData weatherData;

    Display display;
    StatsDisplay statsDisplay;

    weatherData.RegisterObserver(1, display);
    weatherData.RegisterObserver(2, statsDisplay);

    weatherData.SetMeasurements(3, 0.7, 760);

    weatherData.RemoveObserver(display);
    weatherData.RemoveObserver(statsDisplay);
    weatherData.SetMeasurements(5, 0.5, 767);

    return 0;
}