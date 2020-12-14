#pragma once

#include "../Shape/Color.hpp"
#include "../Shape/Point.hpp"

class ICanvas
{
public:
    virtual void SetColor(Color color) = 0;
    virtual void DrawLine(const Point & from, const Point & to) = 0;
    virtual void DrawEllipse(const Point & leftTop, int width, int height) = 0;
};

