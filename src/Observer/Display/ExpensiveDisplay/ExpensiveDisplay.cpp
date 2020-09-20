#include "ExpensiveDisplay.hpp"

void ExpensiveDisplay::Update(const WeatherInfo &data)
{
    m_data.RemoveObserver(*this);
}

ExpensiveDisplay::ExpensiveDisplay(WeatherData &mData) : m_data(mData) {}
