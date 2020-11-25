#pragma once

#include <functional>
#include "../Controller/ControllerType.hpp"
#include "../Controller/IController.hpp"

class IControllerEnumerator
{
public:
    virtual void ForEach(std::function<void(std::pair<const ControllerType, std::unique_ptr<IController>> &)> && callback) = 0;
};