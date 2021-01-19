#pragma once

#include "IControllerRegistry.hpp"
#include "IControllerEnumerator.hpp"
#include <map>

class ControllerRegistry : public IControllerRegistry, public IControllerEnumerator
{
public:
    void Register(const ControllerType &id, std::unique_ptr<IController> controller) override;

    std::unique_ptr<IController> &Get(const ControllerType &id) override;

    void ForEach(std::function<void(std::pair<const ControllerType, std::unique_ptr<IController>> &)> &&callback) override;

private:
    std::map<ControllerType, std::unique_ptr<IController>> m_controllers;
};

