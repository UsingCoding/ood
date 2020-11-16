#pragma once

#include "IControllerRegistry.hpp"
#include <map>

class ControllerRegistry : public IControllerRegistry
{
public:
    void Register(const ControllerType &id, std::unique_ptr<IController> commandHandler) override;

    std::unique_ptr<IController> &Get(const ControllerType &id) override;

private:
    std::map<ControllerType, std::unique_ptr<IController>> m_controllers;
};

