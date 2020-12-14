#include "Canvas.hpp"
#include <iostream>

void Canvas::SetColor(Color color)
{
    m_color = color;
}

void Canvas::DrawLine(const Point & from, const Point & to)
{
    m_output <<
        "<line fromX=" << from.x << " fromY=" << from.y <<
        " toX=" << to.x << " toY=" << to.y << " />" <<
    std::endl;
}

void Canvas::DrawEllipse(const Point & leftTop, int width, int height)
{
    m_output <<
        "<ellipse leftTopX=" << leftTop.x << "leftTopY=" << leftTop.y <<
        "width=" << width << " height=" << height <<
    std::endl;
}
