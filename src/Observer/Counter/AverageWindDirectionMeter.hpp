#pragma once

class AverageWindDirectionMeter
{
public:
    double GetAverage() const;
    void AddIndex(double direction);
private:
    double m_sinusSum;
    double m_cosineSum;
    int m_count;
};

