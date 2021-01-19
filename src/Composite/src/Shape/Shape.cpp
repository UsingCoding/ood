#include "Shape.hpp"
#include "Style/FillStyle.hpp"
#include "Style/OutlineStyle.hpp"
#include <memory>

Shape::Shape()
	: m_outlineStyle(std::make_shared<COutlineStyle>())
	, m_fillStyle(std::make_shared<CFillStyle>())
{
}

void Shape::Draw(ICanvas& canvas)
{
	if (*m_fillStyle->IsEnabled())
	{
		canvas.SetFillColor(*m_fillStyle->GetColor());
	}

	if (*m_outlineStyle->IsEnabled())
	{
		canvas.SetLineColor(*m_outlineStyle->GetColor());
		canvas.SetLineThickness(*m_outlineStyle->GetThickness());
	}

    DoDraw(canvas);
}

std::shared_ptr<IStyle> Shape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<const IStyle> Shape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IOutlineStyle> Shape::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<const IOutlineStyle> Shape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IShapeGroup> Shape::GetGroup()
{
	return nullptr;
}

std::shared_ptr<const IShapeGroup> Shape::GetGroup() const
{
	return nullptr;
}
