#pragma once

#include <memory>
#include <vector>
#include <Application/Input/IInput.hpp>
#include <Application/Output/IOutput.hpp>

namespace Common
{
    class Application
    {
    public:
        void Run(Console::IInput & input, Console::IOutput & output);

    protected:
        virtual void Configure(std::unique_ptr<Console::IInputDefinition> & definition) = 0;
        virtual void DoRun(Console::IInput & input, Console::IOutput & output) = 0;
    };
}