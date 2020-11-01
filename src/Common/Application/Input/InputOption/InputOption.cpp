#include "InputOption.hpp"

using namespace Common::Console;

const std::string &InputOption::GetName() const
{
    return m_name;
}

const std::optional<std::string> &InputOption::GetShortcut() const
{
    return m_shortcut;
}

InputOption::ValueMode InputOption::GetValueMode() const
{
    return m_valueMode;
}

InputOption::MultipleMode InputOption::getMultipleMode() const
{
    return m_multipleMode;
}

const std::optional<std::string> &InputOption::GetDefaultValue() const
{
    return m_defaultValue;
}

bool InputOption::IsValueRequired() const
{
    return m_valueMode == InputOption::ValueMode::VALUE_REQUIRED;
}

bool InputOption::IsValueOptional() const
{
    return m_valueMode == InputOption::ValueMode::VALUE_OPTIONAL;
}

bool InputOption::IsAcceptValue() const
{
    return IsValueRequired() || IsValueOptional();
}

bool InputOption::IsMultiple() const
{
    return m_multipleMode == InputOption::MultipleMode::MULTIPLE;
}

