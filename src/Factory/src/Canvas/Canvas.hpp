#pragma once

#include <iosfwd>
#include "ICanvas.hpp"

class Canvas : public ICanvas
{
public:
    Canvas(std::ostream &output) : m_output(output) {}

    void SetColor(Color color) override;

    void DrawLine(const Point & from, const Point & to) override;

    void DrawEllipse(const Point & leftTop, int width, int height) override;

private:
    std::ostream & m_output;
    Color m_color;
};