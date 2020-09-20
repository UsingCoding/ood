#pragma once

#include "../../WeatherData/WeatherData.hpp"
#include "../../Observer/IObserver.hpp"

class ExpensiveDisplay: public IObserver<WeatherInfo>
{
private:
    WeatherData & m_data;
public:
    ExpensiveDisplay(WeatherData &mData);

    void Update(const WeatherInfo &data) override;
};


