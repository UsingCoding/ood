#include "RegularPolygon.hpp"

const Point &RegularPolygon::GetCenter() const
{
    return m_center;
}

int RegularPolygon::GetRadius() const
{
    return m_radius;
}

int RegularPolygon::GetVertexesCount() const
{
    return m_vertexesCount;
}

void RegularPolygon::Draw(ICanvas &canvas)
{
    for (int i = 0; i < m_vertexesCount; ++i)
    {
            
    }
}
