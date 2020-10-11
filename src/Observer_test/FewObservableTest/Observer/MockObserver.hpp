#pragma once

#include "../../../Observer/Observer/IObserver.hpp"
#include "../../../Observer/WeatherData/WeatherData.hpp"

namespace FewObservableTest
{
    class MockObserver: public IObserver<WeatherInfo>
    {
    public:
        void Update(const WeatherInfo &data) override;

        WeatherDataSource GetSource() const;

    private:
        WeatherDataSource m_source;
    };
}