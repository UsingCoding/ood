#pragma once
#include "Common/Types.hpp"
#include <functional>
#include <optional>

class IStyle
{
public:
    typedef std::function<void(IStyle&)> StyleCallback;

	virtual std::optional<bool> IsEnabled() const = 0;
	virtual void Enable(bool enable) = 0;

	virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};
