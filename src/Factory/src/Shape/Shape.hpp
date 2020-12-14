#pragma once

#include "../Canvas/ICanvas.hpp"

class Shape
{
public:
    Shape(Color color) : m_color(color) {}

    virtual void Draw(ICanvas & canvas) = 0;
    virtual Color GetColor();
    virtual ~Shape() = default;

private:
    Color m_color;
};