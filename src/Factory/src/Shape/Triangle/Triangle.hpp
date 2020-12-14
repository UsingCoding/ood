#pragma once

#include "../Shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(Color color, const Point &vertex1, const Point &vertex2, const Point &vertex3)
    : Shape(color), m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3) {}

    void Draw(ICanvas &canvas) override;

    const Point &GetVertex1() const;

    const Point &GetVertex2() const;

    const Point &GetVertex3() const;

private:
    Point m_vertex1;
    Point m_vertex2;
    Point m_vertex3;
};