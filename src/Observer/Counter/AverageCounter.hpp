#pragma once

#include <limits>

class AverageCounter
{
public:
    double GetMin() const;
    double GetMax() const;
    double GetAverage() const;
    void AddIndex(double index);
private:
    double m_minIndex = std::numeric_limits<double>::infinity();
    double m_maxIndex = -std::numeric_limits<double>::infinity();
    double m_accIndex = 0;
    unsigned m_countIndex = 0;
};
