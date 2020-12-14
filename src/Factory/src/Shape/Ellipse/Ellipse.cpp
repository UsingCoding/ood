#include "Ellipse.hpp"

const Point &Ellipse::GetCenter() const
{
    return m_center;
}

int Ellipse::GetHorizontalRadius() const
{
    return m_horizontalRadius;
}

int Ellipse::GetVerticalRadius() const
{
    return m_verticalRadius;
}

void Ellipse::Draw(ICanvas &canvas)
{
    canvas.DrawEllipse(
        Point{m_center.x + m_horizontalRadius, m_center.y + m_verticalRadius},
        m_horizontalRadius * 2,
        m_verticalRadius * 2
    );
}
