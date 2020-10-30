#include "InputOption.hpp"

Common::Console::InputOption::InputOption(const std::string &name, const std::string &shortcut,
                                          Common::Console::InputOption::ValueMode valueMode,
                                          MultipleMode multipleMode, const std::string &defaultValue)
        : m_name(name), m_shortcut(shortcut), m_valueMode(valueMode), m_default(defaultValue),
          m_multipleMode(multipleMode) {}

const std::string &Common::Console::InputOption::GetName() const
{
    return m_name;
}

const std::string &Common::Console::InputOption::GetShortcut() const
{
    return m_shortcut;
}

Common::Console::InputOption::ValueMode Common::Console::InputOption::GetValueMode() const
{
    return m_valueMode;
}

Common::Console::InputOption::MultipleMode Common::Console::InputOption::getMultipleMode() const
{
    return m_multipleMode;
}

const std::string &Common::Console::InputOption::GetDefaultValue() const
{
    return m_default;
}
