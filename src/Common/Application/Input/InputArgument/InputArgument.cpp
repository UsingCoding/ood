#include "InputArgument.hpp"

using namespace Common::Console;

InputArgument::InputArgument(
        const std::string &name,
        InputArgument::Mode mode,
        const std::string &defaultValue
    ) : m_name(name), m_mode(mode), m_default(defaultValue)
    {}

const std::string &InputArgument::GetName() const
{
    return m_name;
}

InputArgument::Mode InputArgument::GetMode() const
{
    return m_mode;
}

const std::string &InputArgument::GetDefaultValue() const
{
    return m_default;
}
