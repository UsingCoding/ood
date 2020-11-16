#pragma once

#include <string>
#include <memory>
#include "../Controller/IController.hpp"
#include "../Controller/ControllerType.hpp"

class IControllerRegistry
{
public:
    virtual void Register(const ControllerType & id, std::unique_ptr<IController> commandHandler) = 0;
    virtual std::unique_ptr<IController> & Get(const ControllerType & id) = 0;

    virtual ~IControllerRegistry() = default;
};
