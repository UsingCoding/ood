#include <iostream>
#include "WeatherData/WeatherData.hpp"
#include "Display/Display/Display.hpp"
#include "Display/StatsDisplay/StatsDisplay.hpp"

int main()
{
    WeatherData weatherData;

    Display display;
    StatsDisplay statsDisplay;

    weatherData.RegisterObserver(display);
    weatherData.RegisterObserver(statsDisplay);

    weatherData.SetMeasurements(3, 0.7, 760);

    return 0;
}