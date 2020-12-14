#include "Rectangle.hpp"

const Point &Rectangle::GetLeftTop() const
{
    return m_leftTop;
}

const Point &Rectangle::GetRightBottom() const
{
    return m_rightBottom;
}

void Rectangle::Draw(ICanvas &canvas)
{
    canvas.DrawLine(m_leftTop, Point{m_rightBottom.x, m_leftTop.y});
    canvas.DrawLine(Point{m_rightBottom.x, m_leftTop.y}, m_rightBottom);
    canvas.DrawLine(m_rightBottom, Point{m_leftTop.x, m_rightBottom.y});
    canvas.DrawLine(Point{m_leftTop.x, m_rightBottom.y}, m_leftTop);
}
