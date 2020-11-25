#pragma once

#include <string>
#include "../Controller/ControllerType.hpp"

class IControllerCommandsHolder
{
public:
    virtual ControllerType Get(const std::string & command) = 0;
    virtual bool Has(const std::string & command) = 0;
    virtual std::string GetCommandByControllerType(ControllerType controllerType) = 0;

    virtual ~IControllerCommandsHolder() = default;
};
