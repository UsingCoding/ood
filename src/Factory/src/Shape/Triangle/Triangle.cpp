#include "Triangle.hpp"

const Point &Triangle::GetVertex1() const
{
    return m_vertex1;
}

const Point &Triangle::GetVertex2() const
{
    return m_vertex2;
}

const Point &Triangle::GetVertex3() const
{
    return m_vertex3;
}

void Triangle::Draw(ICanvas &canvas)
{
    canvas.DrawLine(m_vertex1, m_vertex2);
    canvas.DrawLine(m_vertex2, m_vertex3);
    canvas.DrawLine(m_vertex3, m_vertex1);
}
