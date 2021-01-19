#pragma once
#include "../IStyle.hpp"
#include <functional>

class CGroupFillStyle : public IStyle
{
public:
    typedef std::function<void(IStyle::StyleCallback)> FillStyleEnumerator;

	CGroupFillStyle(FillStyleEnumerator enumerator);

	std::optional<bool> IsEnabled() const override;
	void Enable(bool enable) override;

	std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	FillStyleEnumerator m_enumerator;
};

