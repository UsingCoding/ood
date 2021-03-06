#pragma once

#include <Application/Input/InputArgument/InputArgument.hpp>
#include <Application/Input/InputOption/InputOption.hpp>
#include <functional>

namespace Common::Console
{
    class IInputDefinition
    {
    public:
        virtual void AddArgument(const InputArgument & argument) = 0;
        virtual void AddOption(const InputOption & option) = 0;

        virtual bool HasArgument(const std::string & name) const = 0;
        virtual bool HasArgument(int index) const = 0;
        virtual bool HasOption(const std::string & name) const = 0;
        virtual bool HasShortcut(char shortcut) const = 0;

        virtual size_t GetArgumentsCount() const = 0;

        virtual const InputArgument & GetArgument(const std::string & name) const = 0;
        virtual const InputArgument & GetArgument(int index) const = 0;
        virtual const InputOption & GetOption(const std::string & name) const = 0;
        virtual const InputOption & GetOptionForShortcut(char shortcut) const = 0;

        virtual const InputArgument & GetLastArgument() const = 0;

        virtual void DoForEachArgument(std::function<void(const InputArgument &)>) const = 0;

        virtual void Clear() = 0;
    };
}
