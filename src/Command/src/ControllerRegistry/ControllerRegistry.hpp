#pragma once

#include "IControllerRegistry.hpp"
#include <map>

class ControllerRegistry : public IControllerRegistry
{
public:
    void Register(const std::string &id, std::unique_ptr<IController> commandHandler) override;

    std::unique_ptr<IController> &Get(const std::string &id) override;

private:
    std::map<std::string, std::unique_ptr<IController>> m_controllers;
};

