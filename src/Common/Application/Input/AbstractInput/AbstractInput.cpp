#include <Strings.hpp>
#include <Arrays.hpp>
#include <list>
#include <iostream>
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

const std::optional<std::string> &AbstractInput::GetArgument(const std::string &name) const
{
    if (!HasArgument(name))
    {
        throw std::logic_error(Strings::Concatenator() << "Argument " << name << " not exists");
    }

    auto searchIterator = m_arguments.find(name);
    return searchIterator != m_arguments.end() ? searchIterator->second : m_inputDefinition->GetArgument(name).GetDefaultValue();
}

const std::optional<std::string> &AbstractInput::GetArgument(int number) const
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
    m_optionsOrder.clear();
    m_arguments.clear();
    m_inputDefinition = std::move(inputDefinition);

    Parse();
}

void AbstractInput::Validate()
{
    std::vector<std::string> missingArgs;

    m_inputDefinition->DoForEachArgument([&](const InputArgument & argument){
        if (argument.IsRequired() && m_arguments.find(argument.GetName()) == m_arguments.end())
        {
            missingArgs.push_back(argument.GetName());
        }
    });

    if (missingArgs.size() != 0)
    {
        throw std::runtime_error("Not enough arguments, missing: " + Arrays::Join(missingArgs.begin(), missingArgs.end(), ", "));
    }
}

const IOptionsEnumerator &AbstractInput::GetOptionsEnumerator()
{
    return *this;
}

void AbstractInput::ForEach(std::function<void(const std::string &, const std::optional<std::string> &)> function) const
{
    std::for_each(m_optionsOrder.begin(), m_optionsOrder.end(), [&](const std::string & optionNameAndValue) {
        ProceedEnumeration(function, optionNameAndValue);
    });
}

void AbstractInput::ForEachReverse(std::function<void(const std::string &, const std::optional<std::string> &)> function) const
{
    std::for_each(m_optionsOrder.rbegin(), m_optionsOrder.rend(), [&](const std::string & optionNameAndValue) {
        ProceedEnumeration(function, optionNameAndValue);
    });
}

void AbstractInput::ProceedEnumeration(
    std::function<void(const std::string &, const std::optional<std::string> &)> function,
    const std::string &optionNameAndValue) const
{
    auto parts = Strings::Split(optionNameAndValue, "=");

    auto option = m_inputDefinition->GetOption(parts[0]);

    if (parts[0].size() == 1)
    {
        option = m_inputDefinition->GetOptionForShortcut(parts[0][0]);
    }

    auto value = option.IsAcceptValue() && parts.size() > 1 ? parts[1] : option.GetDefaultValue();

    function(parts[0], parts.size() == 1 ? std::nullopt : value);
}

std::istream &AbstractInput::operator*()
{
    return m_istream;
}
