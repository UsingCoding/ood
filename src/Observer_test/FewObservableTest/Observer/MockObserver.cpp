#include "MockObserver.hpp"

void FewObservableTest::MockObserver::Update(const WeatherInfo &data)
{
    m_source = data.m_source;
}

WeatherDataSource FewObservableTest::MockObserver::GetSource() const
{
    return m_source;
}
