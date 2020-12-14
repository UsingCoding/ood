#include "PictureDraft.hpp"

int PictureDraft::GetShapeCount()
{
    return m_shapes->size();
}

std::unique_ptr<Shape> &PictureDraft::GetShape(int index)
{
    if (index >= m_shapes->size())
    {
        throw std::invalid_argument("Trying to access shape index more than shapes");
    }

    return m_shapes->at(index);
}
