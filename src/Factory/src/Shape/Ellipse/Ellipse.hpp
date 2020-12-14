#pragma once

#include "../Shape.hpp"

class Ellipse : public Shape
{
public:
    Ellipse(Color color, const Point &center, int horizontalRadius, int verticalRadius)
    : Shape(color), m_center(center), m_horizontalRadius(horizontalRadius), m_verticalRadius(verticalRadius) {}

    const Point &GetCenter() const;

    int GetHorizontalRadius() const;

    int GetVerticalRadius() const;

    void Draw(ICanvas &canvas) override;

private:
    Point m_center;
    int m_horizontalRadius;
    int m_verticalRadius;
};
