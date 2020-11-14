#pragma once

#include "IControllerRegistry.hpp"
#include <map>

class ControllerRegistry : public IControllerRegistry
{
public:
    void RegisterHandler(const std::string &id, std::unique_ptr<IController> commandHandler) override;

    std::unique_ptr<IController> &GetHandler(const std::string &id) override;

private:
    std::map<std::string, std::unique_ptr<IController>> m_handlers;
};

