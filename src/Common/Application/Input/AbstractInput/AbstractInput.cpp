#include <Strings.hpp>
#include "AbstractInput.hpp"

using namespace Common::Console;

bool AbstractInput::HasArgument(const std::string &name) const
{
    return m_inputDefinition->HasArgument(name);
}

bool AbstractInput::HasOption(const std::string &name) const
{
    return m_inputDefinition->HasOption(name);
}

const std::string &AbstractInput::GetArgument(const std::string &name) const
{
    if (!HasArgument(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Argument " << name << " not exists");
    }

    auto searchIterator = m_arguments.find(name);
    return searchIterator != m_arguments.end() ? searchIterator->second : m_inputDefinition->GetArgument(name).GetDefaultValue().value();
}

const std::string &AbstractInput::GetArgument(int number) const
{
    if (m_arguments.size() >= number)
    {
        throw std::runtime_error("Accessing offset more than count of arguments");
    }

    for (auto [i, it] = std::tuple{0, m_arguments.begin()}; it != m_arguments.end(); it++, i++)
    {
        if (i == number)
        {
            return it->second;
        }
    }

    throw std::runtime_error(Strings::Concatenator() << "No argument found by number " << number);
}

const std::optional<std::string> &AbstractInput::GetOption(const std::string &name) const
{
    if (!HasOption(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Option " << name << " not exists");
    }

    auto searchIterator = m_options.find(name);

    return searchIterator != m_options.end() ? searchIterator->second : m_inputDefinition->GetOption(name).GetDefaultValue();
}

void AbstractInput::Bind(std::unique_ptr<IInputDefinition> inputDefinition)
{
    m_options.clear();
    m_arguments.clear();
    m_inputDefinition = std::move(inputDefinition);

    Parse();
}

void AbstractInput::Validate()
{

}