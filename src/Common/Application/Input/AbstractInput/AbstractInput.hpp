#pragma once

#include <Application/Input/IInput.hpp>
#include <map>
#include "IOptionsEnumerator.hpp"

namespace Common::Console
{
    class AbstractInput : public IInput, IOptionsEnumerator
    {
    public:
        AbstractInput(std::istream &istream) : m_istream(istream) {}

        void Bind(std::unique_ptr<IInputDefinition> inputDefinition) override;

        void Validate() override;

        bool HasArgument(const std::string &name) const override;

        bool HasOption(const std::string &name) const override;

        const std::optional<std::string> &GetArgument(const std::string &name) const override;

        const std::optional<std::string> &GetArgument(int number) const override;

        const std::optional<std::string> &GetOption(const std::string &name) const override;

        const IOptionsEnumerator &GetOptionsEnumerator() override;

        void ForEach(std::function<void(const std::string &, const std::optional<std::string> &)> function) const override;
        void ForEachReverse(std::function<void(const std::string &, const std::optional<std::string> &)> function) const override;

        std::istream &operator*() override;

    protected:
        virtual void Parse() = 0;

        std::unique_ptr<IInputDefinition> m_inputDefinition;
        std::map<std::string, std::optional<std::string>> m_arguments;
        std::multimap<std::string, std::optional<std::string>> m_options;
        std::vector<std::string> m_optionsOrder;

    private:
        void ProceedEnumeration(
            std::function<void(const std::string &, const std::optional<std::string> &)> function,
            const std::string & optionNameAndValue) const;

        std::istream & m_istream;
    };
}
