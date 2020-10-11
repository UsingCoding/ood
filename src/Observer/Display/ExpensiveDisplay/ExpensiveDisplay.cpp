#include "ExpensiveDisplay.hpp"

void ExpensiveDisplay::Update(const WeatherInfo &data)
{
    std::cout << "Update received from " << (data.m_source == WeatherDataSource::IN ? "Inner sensor" : "Outer sensor") << std::endl;
}

ExpensiveDisplay::ExpensiveDisplay(WeatherData &mData) : m_data(mData) {}
