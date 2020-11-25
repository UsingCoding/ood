#pragma once

#include "IInputDefinition.hpp"

#include <map>

namespace Common::Console
{
    class InputDefinition : public IInputDefinition
    {
    public:
        void AddArgument(const InputArgument &argument) override;
        void AddOption(const InputOption &option) override;

        bool HasArgument(const std::string &name) const override;
        bool HasArgument(int index) const override;
        bool HasOption(const std::string &name) const override;
        bool HasShortcut(char shortcut) const override;

        const InputArgument &GetArgument(const std::string &name) const override;
        const InputArgument &GetArgument(int index) const override;
        const InputOption &GetOption(const std::string &name) const override;
        const InputOption &GetOptionForShortcut(char shortcut) const override;

        void DoForEachArgument(std::function<void(const InputArgument &)> function) const override;

        void Clear() override;

    private:
        std::map<std::string, InputArgument> m_arguments;
        std::vector<std::string> m_argumentsOrder;
        std::map<std::string, InputOption> m_options;
        std::map<char, std::string> m_shortcuts;
    };
}
