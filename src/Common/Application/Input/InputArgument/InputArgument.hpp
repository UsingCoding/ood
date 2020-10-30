#pragma once

#include <string>

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

        InputArgument(const std::string &name, Mode mode, const std::string &defaultValue);

        const std::string &GetName() const;

        Mode GetMode() const;

        const std::string &GetDefaultValue() const;

    private:
        std::string m_name;
        Mode m_mode;
        std::string m_default;
    };
}


