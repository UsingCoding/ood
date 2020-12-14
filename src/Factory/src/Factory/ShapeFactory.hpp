#pragma once

#include <memory>
#include "IShapeFactory.hpp"

class ShapeFactory : public IShapeFactory
{
public:
    std::unique_ptr<Shape> CreateShape(const std::string &description) override;

private:
    static const std::string RECTANGLE_KEY_WORD;
    static const std::string TRIANGLE_KEY_WORD;
    static const std::string ELLIPSE_KEY_WORD;
    static const std::string REGULAR_POLYGON_KEY_WORD;

    static const std::string GREEN_COLOR_KEY_WORD;
    static const std::string RED_COLOR_KEY_WORD;
    static const std::string BLUE_COLOR_KEY_WORD;
    static const std::string YELLOW_COLOR_KEY_WORD;
    static const std::string PINK_COLOR_KEY_WORD;
    static const std::string BLACK_COLOR_KEY_WORD;

    std::unique_ptr<Shape> CreateRectangle(const std::vector<std::string> & tokens);
    std::unique_ptr<Shape> CreateTriangle(const std::vector<std::string> & tokens);
    std::unique_ptr<Shape> CreateEllipse(const std::vector<std::string> & tokens);
    std::unique_ptr<Shape> CreateRegularPolygon(const std::vector<std::string> & tokens);

    static Color GetColor(const std::string & color);
    static Point GetPoint(const std::string & firstCoord, const std::string & secondCoord);
};