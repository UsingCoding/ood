#pragma once

#include <vector>

#include <Application/Input/IInput.hpp>
#include <Application/Input/AbstractInput/AbstractInput.hpp>

namespace Common::Console
{
    class ArgvInput : public AbstractInput
    {
    public:
        typedef std::vector<std::string> ArgsContainer;

        ArgvInput(int argc, char const *argv[]);
        ArgvInput(std::unique_ptr<ArgsContainer> container);

    protected:
        void Parse() override;

    private:
        void ParseArgument(const std::string & token);
        void ParseLongOption(const std::string & token);
        void ParseShortOption(const std::string & token);

        void AddLongOption(const std::string & name, const std::optional<std::string> & value = std::nullopt);

        std::unique_ptr<ArgsContainer> m_tokens;

        constexpr const static std::string_view OPTION_PREFIX = "--";
        constexpr const static std::string_view SHORT_OPTION_PREFIX = "-";
        constexpr const static std::string_view KEY_VALUE_SEPARATOR = "=";
    };
}



