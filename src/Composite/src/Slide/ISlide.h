#pragma once
#include "../Shape/Common/Types.h"
#include "../Canvas/IDrawable.h"
#include <optional>
#include "../Shape/IShape.h"

class ISlide : public IDrawable
{
public:
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;
    virtual size_t GetShapesCount() const = 0;
    virtual void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
    virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const = 0;
    virtual void RemoveShapeAtIndex(size_t index) = 0;

	virtual ~ISlide() = default;
};
