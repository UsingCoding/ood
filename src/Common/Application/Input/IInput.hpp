#pragma once

#include <Application/Input/InputArgument/InputArgument.hpp>
#include <Application/Input/InputOption/InputOption.hpp>
#include <Application/InputDefinition/IInputDefinition.hpp>
#include <memory>
#include <optional>
#include <Application/Input/AbstractInput/IOptionsEnumerator.hpp>

namespace Common::Console
{
    class IInput
    {
    public:
        virtual void Bind(std::unique_ptr<IInputDefinition> inputDefinition) = 0;
        virtual void Validate() = 0;

        virtual bool HasArgument(const std::string & name) const = 0;
        virtual bool HasOption(const std::string & name) const = 0;

        virtual const std::optional<std::string> & GetArgument(const std::string & name) const = 0;
        virtual const std::optional<std::string> & GetArgument(int number) const = 0;
        virtual const std::optional<std::string> & GetOption(const std::string & name) const = 0;

        virtual const IOptionsEnumerator & GetOptionsEnumerator() = 0;

        virtual std::istream & operator*() = 0;
    };
}