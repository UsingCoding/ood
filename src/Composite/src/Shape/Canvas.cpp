#include <iostream>
#include "Canvas.hpp"

Canvas::Canvas(std::ostream &output) : m_output(output) {}

void Canvas::SetLineColor(RGBAColor color)
{
	m_lineColor = color;
}

void Canvas::SetFillColor(RGBAColor color)
{
	m_fillColor = color;
}

void Canvas::SetLineThickness(double thickness)
{
	m_lineThickness = (float)thickness;
}

void Canvas::DrawLine(PointD const& from, PointD const& to)
{
    m_output <<
             "<line color=" << m_lineColor << " lineThickness=" << m_lineThickness <<
             " fromX=" << from.x << " fromY=" << from.y <<
             " toX=" << to.x << " toY=" << to.y << " />" <<
    std::endl;
}

void Canvas::FillPolygon(std::vector<PointD> const& vertexes)
{
    m_output << "<polygon color=" << m_lineColor << "lineThickness=" << m_lineThickness << ">";

    for (auto & vertex : vertexes)
    {
        m_output << "  <point x=" << vertex.x << " y=" << vertex.y << "</point>";
    }

    m_output << "</polygon>" << std::endl;
}

void Canvas::DrawEllipse(double left, double top, double width, double height)
{
    m_output <<
        "<ellipse color=" << m_lineColor << " leftTopX=" << left << "leftTopY=" << top <<
        "width=" << width << " height=" << height << "lineThickness=" << m_lineThickness <<
    std::endl;
}

void Canvas::FillEllipse(double left, double top, double width, double height)
{
    m_output <<
             "<ellipse color=" << m_lineColor << " leftTopX=" << left << "leftTopY=" << top <<
             "width=" << width << " height=" << height << "lineThickness=" << m_lineThickness <<
    std::endl;
}
