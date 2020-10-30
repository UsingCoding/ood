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
}

bool InputDefinition::HasArgument(const std::string &name) const
{
    return m_arguments.find(name) != m_arguments.end();
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

const InputOption &InputDefinition::GetOption(const std::string &name) const
{
    if (!HasOption(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Option " << name << " is not registered");
    }

    return m_options.find(name)->second;
}
