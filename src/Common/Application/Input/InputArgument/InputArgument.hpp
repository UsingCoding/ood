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

        InputArgument(
            const std::string &name,
            InputArgument::Mode mode = Mode::REQUIRED,
            const std::optional<std::string> &defaultValue = std::nullopt
        )
        : m_name(name), m_mode(mode), m_default(defaultValue)
        {}

        const std::string &GetName() const;

        Mode GetMode() const;

        const std::optional<std::string> &GetDefaultValue() const;

    private:
        std::string m_name;
        Mode m_mode;
        std::optional<std::string> m_default;
    };
}


