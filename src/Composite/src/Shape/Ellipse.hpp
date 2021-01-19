#pragma once
#include "Shape.hpp"

class CEllipse : public Shape
{
public:
	CEllipse(PointD const& center, double horizontalRadius, double verticalRadius);

	std::optional<RectD> GetFrame() const override;
	void SetFrame(const RectD& rect) override;

	void DoDraw(ICanvas& canvas) const override;

private:
	PointD m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
