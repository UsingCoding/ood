#pragma once

#include <memory>
#include <vector>
#include "../Shape/Shape.hpp"

class PictureDraft
{
public:
    PictureDraft(std::unique_ptr<std::vector<std::unique_ptr<Shape>>> && shapes) : m_shapes(std::move(shapes)) {}

    int GetShapeCount();
    std::unique_ptr<Shape> & GetShape(int index);

private:
    std::unique_ptr<std::vector<std::unique_ptr<Shape>>> m_shapes;
};
