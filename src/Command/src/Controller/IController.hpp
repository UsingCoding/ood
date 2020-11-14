#pragma once

#include <vector>
#include <Application/Output/IOutput.hpp>
#include <Application/Input/IInput.hpp>

class IController
{
public:
    virtual void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> & definition) = 0;
    virtual void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) = 0;

    virtual ~IController() = default;
};
