#pragma once

#include "../../Observer/IObserver.hpp"
#include "../../WeatherData/WeatherData.hpp"

class Display: public IObserver<WeatherInfo>
{
private:
    void Update(const WeatherInfo & data) override;
};

