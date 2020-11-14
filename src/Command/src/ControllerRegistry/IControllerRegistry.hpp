#pragma once

#include <string>
#include <memory>
#include "../Controller/IController.hpp"

class IControllerRegistry
{
public:
    virtual void Register(const std::string & id, std::unique_ptr<IController> commandHandler) = 0;
    virtual std::unique_ptr<IController> & Get(const std::string & id) = 0;

    virtual ~IControllerRegistry() = default;
};
