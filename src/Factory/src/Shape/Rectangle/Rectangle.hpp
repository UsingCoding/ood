#pragma once

#include "../Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(Color color, const Point &leftTop, const Point &rightBottom)
    : Shape(color), m_leftTop(leftTop), m_rightBottom(rightBottom) {}

    const Point &GetLeftTop() const;

    const Point &GetRightBottom() const;

    void Draw(ICanvas &canvas) override;

private:
    Point m_leftTop;
    Point m_rightBottom;
};