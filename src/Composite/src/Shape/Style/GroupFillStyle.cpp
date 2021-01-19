#include "GroupFillStyle.h"

CGroupFillStyle::CGroupFillStyle(FillStyleEnumerator enumerator)
	: m_enumerator(enumerator)
{
}

std::optional<bool> CGroupFillStyle::IsEnabled() const
{
	std::optional<bool> isEnabled = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IStyle& style) {
        if (!isInit)
        {
            isEnabled = style.IsEnabled();
            isInit = true;
        }
        else if (isEnabled != style.IsEnabled())
        {
            isEnabled = std::nullopt;
        }
    });

	return isEnabled;
}

void CGroupFillStyle::Enable(bool enable)
{
	m_enumerator([&](IStyle& style) {
        style.Enable(enable);
    });
}

std::optional<RGBAColor> CGroupFillStyle::GetColor() const
{
	std::optional<RGBAColor> color = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IStyle& style) {
        if (!isInit)
        {
            color = style.GetColor();
            isInit = true;
        }
        else if (color != style.GetColor())
        {
            color = std::nullopt;
        }
    });

	return color;
}

void CGroupFillStyle::SetColor(RGBAColor color)
{
	m_enumerator([&](IStyle& style) {
        style.SetColor(color);
    });
}
