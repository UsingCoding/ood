#include <Strings.hpp>
#include "InputDefinition.hpp"

using namespace Common::Console;

void InputDefinition::AddArgument(const InputArgument &argument)
{
    if (HasArgument(argument.GetName()))
    {
        throw std::logic_error(Strings::Concatenator() << "Argument " << argument.GetName() << " already added to definition");
    }

    m_arguments.insert(std::make_pair(argument.GetName(), argument));
}

void InputDefinition::AddOption(const InputOption &option)
{
    if (HasOption(option.GetName()))
    {
        throw std::logic_error(Strings::Concatenator() << "Option " << option.GetName() << " already added to definition");
    }

    m_options.insert(std::make_pair(option.GetName(), option));

    if (option.GetShortcut().has_value())
    {
        if (HasShortcut(option.GetShortcut().value()))
        {
            throw std::logic_error(Strings::Concatenator() << "Shortcut " << option.GetShortcut().value() << " already set for another option");
        }

        m_shortcuts[option.GetShortcut().value()] = option.GetName();
    }
}

bool InputDefinition::HasArgument(const std::string &name) const
{
    return m_arguments.find(name) != m_arguments.end();
}

bool InputDefinition::HasArgument(int index) const
{
    if (m_arguments.size() <= index)
    {
        return false;
    }

    for (auto [i, it] = std::tuple{0, m_arguments.begin()}; it != m_arguments.end(); it++, i++)
    {
        if (i == index)
        {
            return true;
        }
    }

    throw false;
}

bool InputDefinition::HasOption(const std::string &name) const
{
    return m_options.find(name) != m_options.end();
}

const InputArgument &InputDefinition::GetArgument(const std::string &name) const
{
    if (!HasArgument(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Argument " << name << " is not registered");
    }

    return m_arguments.find(name)->second;
}

const InputArgument &InputDefinition::GetArgument(int index) const
{
    if (!HasArgument(index))
    {
        throw std::runtime_error("Accessing offset more than count of arguments");
    }

    for (auto [i, it] = std::tuple{0, m_arguments.begin()}; it != m_arguments.end(); it++, i++)
    {
        if (i == index)
        {
            return it->second;
        }
    }

    throw std::runtime_error(Strings::Concatenator() << "No argument found by index " << index);
}

const InputOption &InputDefinition::GetOption(const std::string &name) const
{
    if (!HasOption(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Option " << name << " is not registered");
    }

    return m_options.find(name)->second;
}

void InputDefinition::DoForEachArgument(std::function<void(const InputArgument &)> function) const
{
    std::for_each(m_arguments.begin(), m_arguments.end(), [function](const std::pair<std::string, InputArgument> pair){
        function(pair.second);
    });
}

bool InputDefinition::HasShortcut(char shortcut) const
{
    return m_shortcuts.find(shortcut) != m_shortcuts.end();
}

const InputOption &InputDefinition::GetOptionForShortcut(char shortcut) const
{
    auto searchIterator = m_shortcuts.find(shortcut);

    if (searchIterator == m_shortcuts.end())
    {
        throw std::invalid_argument(Strings::Concatenator() << "No option for shortcut " << shortcut <<" found");
    }

    return m_options.find(searchIterator->second)->second;
}
