#pragma once

#include <string>
#include <optional>

namespace Common::Console
{
    class InputArgument
    {
    public:
        enum class Mode
        {
            OPTIONAL,
            REQUIRED
        };

        enum class ValueMode
        {
            SINGLE,
            TEXT
        };

        InputArgument(
            const std::string &name,
            Mode mode = Mode::REQUIRED,
            ValueMode valueMode = ValueMode::SINGLE,
            const std::optional<std::string> &defaultValue = std::nullopt
        )
        : m_name(name), m_mode(mode), m_valueMode(valueMode), m_default(defaultValue)
        {}

        const std::string &GetName() const;

        Mode GetMode() const;

        ValueMode GetValueMode() const;

        const std::optional<std::string> &GetDefaultValue() const;

        bool IsRequired() const;

    private:
        std::string m_name;
        Mode m_mode;
        ValueMode m_valueMode;
        std::optional<std::string> m_default;
    };
}


