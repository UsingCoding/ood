#include "RegularPolygon.hpp"
#include <cmath>
#include <optional>

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
    int angle = 2 * M_PI / m_vertexesCount;

    std::optional<Point> prevPoint = std::nullopt;

    for (int i = 0; i < m_vertexesCount; ++i)
    {
        int x = m_center.x + m_radius * sin(i * angle);
        int y = m_center.y + m_radius * cos(i * angle);

        if (prevPoint != std::nullopt)
        {
            canvas.DrawLine(prevPoint.value(), {x, y});
        }

        prevPoint = {x, y};
    }
}
