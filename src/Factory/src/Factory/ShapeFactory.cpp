#include <Strings.hpp>
#include "ShapeFactory.hpp"
#include "../Shape/Triangle/Triangle.hpp"
#include "../Shape/Rectangle/Rectangle.hpp"
#include "../Shape/Ellipse/Ellipse.hpp"
#include "../Shape/RegularPolygon/RegularPolygon.hpp"

const std::string ShapeFactory::RECTANGLE_KEY_WORD = "rectangle";
const std::string ShapeFactory::TRIANGLE_KEY_WORD = "triangle";
const std::string ShapeFactory::ELLIPSE_KEY_WORD = "ellipse";
const std::string ShapeFactory::REGULAR_POLYGON_KEY_WORD = "regular-polygon";

const std::string ShapeFactory::GREEN_COLOR_KEY_WORD = "green";
const std::string ShapeFactory::RED_COLOR_KEY_WORD = "red";
const std::string ShapeFactory::BLUE_COLOR_KEY_WORD = "blue";
const std::string ShapeFactory::YELLOW_COLOR_KEY_WORD = "yellow";
const std::string ShapeFactory::PINK_COLOR_KEY_WORD = "pink";
const std::string ShapeFactory::BLACK_COLOR_KEY_WORD = "black";

std::unique_ptr<Shape> ShapeFactory::CreateShape(const std::string &description)
{
    auto tokens = Strings::Split(description, " ");

    if (tokens.size() == 0)
    {
        throw std::invalid_argument("No enough arguments to create shape");
    }

    auto shapeKeyWord = tokens[0];

    tokens.erase(tokens.begin());

    if (shapeKeyWord == RECTANGLE_KEY_WORD)
    {
        return CreateRectangle(tokens);
    }

    if (shapeKeyWord == TRIANGLE_KEY_WORD)
    {
        return CreateTriangle(tokens);
    }

    if (shapeKeyWord == ELLIPSE_KEY_WORD)
    {
        return CreateEllipse(tokens);
    }

    if (shapeKeyWord == REGULAR_POLYGON_KEY_WORD)
    {
        return CreateRegularPolygon(tokens);
    }

    throw std::invalid_argument("Unknown shape type");
}

std::unique_ptr<Shape> ShapeFactory::CreateRectangle(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 5)
    {
        throw std::invalid_argument("Not enough args to create Rectangle");
    }

    return std::make_unique<Rectangle>(
        GetColor(tokens[0]),
        GetPoint(tokens[1], tokens[2]),
        GetPoint(tokens[3], tokens[4])
    );
}

std::unique_ptr<Shape> ShapeFactory::CreateTriangle(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 7)
    {
        throw std::invalid_argument("Not enough args to create Triangle");
    }

    return std::make_unique<Triangle>(
        GetColor(tokens[0]),
        GetPoint(tokens[1], tokens[2]),
        GetPoint(tokens[3], tokens[4]),
        GetPoint(tokens[5], tokens[6])
    );
}

std::unique_ptr<Shape> ShapeFactory::CreateEllipse(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 5)
    {
        throw std::invalid_argument("Not enough args to create Ellipse");
    }

    int horizontalRadius;
    int verticalRadius;

    try
    {
        horizontalRadius = std::stoi(tokens[3]);
        verticalRadius = std::stoi(tokens[4]);
    }
    catch (const std::exception & e)
    {
        throw std::invalid_argument("Failed parse ellipse horizontal or vertical radius");
    }

    return std::make_unique<Ellipse>(
        GetColor(tokens[0]),
        GetPoint(tokens[1], tokens[2]),
        horizontalRadius,
        verticalRadius
    );
}

std::unique_ptr<Shape> ShapeFactory::CreateRegularPolygon(const std::vector<std::string> &tokens)
{
    if (tokens.size() != 5)
    {
        throw std::invalid_argument("Not enough args to create Regular polygon");
    }

    int radius;
    int vertexesCount;

    try
    {
        radius = std::stoi(tokens[3]);
        vertexesCount = std::stoi(tokens[4]);
    }
    catch (const std::exception & e)
    {
        throw std::invalid_argument("Failed parse regular polygon radius or vertexes count");
    }

    return std::make_unique<RegularPolygon>(
        GetColor(tokens[0]),
        GetPoint(tokens[1], tokens[2]),
        radius,
        vertexesCount
    );
}

Color ShapeFactory::GetColor(const std::string &color)
{
    if (color == GREEN_COLOR_KEY_WORD)
    {
        return Color::GREEN;
    }

    if (color == RED_COLOR_KEY_WORD)
    {
        return Color::RED;
    }

    if (color == BLUE_COLOR_KEY_WORD)
    {
        return Color::BLUE;
    }

    if (color == YELLOW_COLOR_KEY_WORD)
    {
        return Color::YELLOW;
    }

    if (color == PINK_COLOR_KEY_WORD)
    {
        return Color::PINK;
    }

    if (color == BLACK_COLOR_KEY_WORD)
    {
        return Color::BLACK;
    }

    throw std::invalid_argument("Unknown color");
}

Point ShapeFactory::GetPoint(const std::string &firstCoord, const std::string &secondCoord)
{
    try
    {
        return Point{std::stoi(firstCoord), std::stoi(secondCoord)};
    }
    catch (const std::exception & e)
    {
        throw std::invalid_argument("Failed to get coords");
    }
}

