#pragma once

#include <Application/Input/IInput.hpp>
#include <map>

namespace Common::Console
{
    class AbstractInput : public IInput
    {
    public:
        void Bind(std::unique_ptr<IInputDefinition> inputDefinition) override;

        bool HasArgument(const std::string &name) const override;

        bool HasOption(const std::string &name) const override;

        const std::string &GetArgument(const std::string &name) const override;

        const std::string &GetArgument(int number) const override;

        const std::string &GetOption(const std::string &name) const override;

        virtual void Parse() = 0;

    protected:
        std::unique_ptr<IInputDefinition> m_inputDefinition;
        std::multimap<std::string, std::string> m_arguments;
        std::multimap<std::string, std::string> m_options;
    };
}
