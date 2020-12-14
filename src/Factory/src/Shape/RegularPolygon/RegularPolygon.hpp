#pragma once

#include <vector>
#include "../Shape.hpp"

class RegularPolygon : public Shape
{
public:
    RegularPolygon(Color color, const Point &center, int radius, int vertexesCount)
    : Shape(color), m_center(center), m_radius(radius), m_vertexesCount(vertexesCount) {}

    const Point &GetCenter() const;

    int GetRadius() const;

    int GetVertexesCount() const;

    void Draw(ICanvas &canvas) override;

private:
    Point m_center;
    int m_radius;
    int m_vertexesCount;
};

