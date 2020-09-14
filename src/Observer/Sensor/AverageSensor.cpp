#include "AverageSensor.hpp"

void AverageSensor::AddIndex(double index)
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

double AverageSensor::GetMin() const
{
    return m_minIndex;
}

double AverageSensor::GetMax() const
{
    return m_maxIndex;
}

double AverageSensor::GetAverage() const
{
    return (m_accIndex / m_countIndex);
}
