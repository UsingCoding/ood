#pragma once

#include <string>
#include <optional>

namespace Common::Console
{
    class InputOption
    {
    public:
        enum class ValueMode
        {
            VALUE_OPTIONAL,
            VALUE_REQUIRED
        };

        enum class MultipleMode
        {
            SINGLE,
            MULTIPLE
        };

        InputOption(
                const std::string &name,
                const std::optional<std::string> &shortcut = std::nullopt,
                ValueMode valueMode = ValueMode::VALUE_REQUIRED,
                MultipleMode multipleMode = MultipleMode::SINGLE,
                const std::optional<std::string> &defaultValue = std::nullopt
        ):
                m_name(name),
                m_shortcut(shortcut),
                m_valueMode(valueMode),
                m_multipleMode(multipleMode),
                m_defaultValue(defaultValue)
        {}

        const std::string &GetName() const;

        const std::optional<std::string> &GetShortcut() const;

        ValueMode GetValueMode() const;

        MultipleMode getMultipleMode() const;

        const std::optional<std::string> &GetDefaultValue() const;

        bool IsValueRequired() const;
        bool IsValueOptional() const;
        bool IsAcceptValue() const;
        bool IsMultiple() const;

    private:
        std::string m_name;
        std::optional<std::string> m_shortcut;
        ValueMode m_valueMode;
        MultipleMode m_multipleMode;
        std::optional<std::string> m_defaultValue;
    };
}
