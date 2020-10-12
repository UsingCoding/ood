#include "AverageWindDirectionMeter.hpp"
#include <cmath>

double ToRadians(double value)
{
    return value * M_PI / 180;
}

double ToDegrees(double value)
{
    return value * 180 / M_PI;
}

double AverageWindDirectionMeter::GetAverage() const
{
    double x = ToDegrees(atan2(m_sinusSum, m_cosineSum)) + 360;
    return x - trunc(x / 360) * 360;
}

void AverageWindDirectionMeter::AddIndex(double direction)
{
    m_sinusSum += sin(ToRadians(direction));
    m_cosineSum += cos(ToRadians(direction));
}
