#pragma once

#include <string>

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

        InputOption(const std::string &name,
                    const std::string &shortcut,
                    ValueMode valueMode,
                    MultipleMode multipleMode,
                    const std::string &defaultValue);

        const std::string &GetName() const;

        const std::string &GetShortcut() const;

        ValueMode GetValueMode() const;

        MultipleMode getMultipleMode() const;

        const std::string &GetDefaultValue() const;

    private:
        std::string m_name;
        std::string m_shortcut;
        ValueMode m_valueMode;
        MultipleMode m_multipleMode;
        std::string m_default;
    };
}
