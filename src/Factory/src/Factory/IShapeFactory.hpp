#pragma once

#include <string>
#include "../Shape/Shape.hpp"

class IShapeFactory
{
public:
    virtual std::unique_ptr<Shape> CreateShape(const std::string & description) = 0;
    virtual ~IShapeFactory() = default;
};
