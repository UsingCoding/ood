#include "AverageCounter.hpp"

void AverageCounter::AddIndex(double index)
{
    if (m_minIndex > index)
    {
        m_minIndex = index;
    }
    if (m_maxIndex < index)
    {
        m_maxIndex = index;
    }
    m_accIndex += index;
    ++m_countIndex;
}

double AverageCounter::GetMin() const
{
    return m_minIndex;
}

double AverageCounter::GetMax() const
{
    return m_maxIndex;
}

double AverageCounter::GetAverage() const
{
    return (m_accIndex / m_countIndex);
}
