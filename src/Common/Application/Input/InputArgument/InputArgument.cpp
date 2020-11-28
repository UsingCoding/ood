#include "InputArgument.hpp"

using namespace Common::Console;

const std::string &InputArgument::GetName() const
{
    return m_name;
}

InputArgument::Mode InputArgument::GetMode() const
{
    return m_mode;
}

const std::optional<std::string> &InputArgument::GetDefaultValue() const
{
    return m_default;
}

bool InputArgument::IsRequired() const
{
    return m_mode == Mode::REQUIRED;
}

InputArgument::ValueMode InputArgument::GetValueMode() const
{
    return m_valueMode;
}
