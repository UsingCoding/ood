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
        bool HasOption(const std::string &name) const override;

        const InputArgument &GetArgument(const std::string &name) const override;
        const InputOption &GetOption(const std::string &name) const override;

    private:
        std::map<std::string, InputArgument> m_arguments;
        std::map<std::string, InputOption> m_options;
    };
}
