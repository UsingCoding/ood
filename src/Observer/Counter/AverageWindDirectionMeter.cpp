#include "AverageWindDirectionMeter.hpp"
#include <cmath>

double AverageWindDirectionMeter::GetAverage() const
{
    auto sinSum = m_sinusSum / m_count;
    auto cosSum = m_cosineSum / m_count;

    auto averageDir = (int) ((atan2(sinSum, cosSum) * 180 / M_PI) + 360) % 360;
    auto someAvDir = sqrt(cosSum * cosSum + sinSum * sinSum);

    return someAvDir;
}

void AverageWindDirectionMeter::AddIndex(double speed, double direction)
{
    m_sinusSum += speed * sin(direction);
    m_cosineSum += speed * cos(direction);
    ++m_count;
}
