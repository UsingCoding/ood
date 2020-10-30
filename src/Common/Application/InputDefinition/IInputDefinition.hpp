#pragma once

#include <Application/Input/InputArgument/InputArgument.hpp>
#include <Application/Input/InputOption/InputOption.hpp>

namespace Common::Console
{
    class IInputDefinition
    {
    public:
        virtual void AddArgument(const InputArgument & argument) = 0;
        virtual void AddOption(const InputOption & option) = 0;

        virtual bool HasArgument(const std::string & name) const = 0;
        virtual bool HasOption(const std::string & name) const = 0;

        virtual const InputArgument & GetArgument(const std::string & name) const = 0;
        virtual const InputOption & GetOption(const std::string & name) const = 0;
    };
}
