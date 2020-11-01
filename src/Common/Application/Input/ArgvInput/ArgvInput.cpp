#include <algorithm>
#include <Strings.hpp>
#include <iostream>
#include "ArgvInput.hpp"

using namespace Common::Console;

ArgvInput::ArgvInput(int argc, const char **argv)
{
    m_tokens = std::make_unique<std::vector<std::string>>();

    for (int i = 0; i < argc; ++i)
    {
        m_tokens->push_back(argv[i]);
    }
}

void ArgvInput::Parse()
{
    std::for_each(m_tokens->begin(), m_tokens->end(), [&](const std::string & token){
        if (Strings::StartsWith(token, (std::string) OPTION_PREFIX))
        {
            ParseLongOption(token);
            return;
        }

        if (Strings::StartsWith(token, (std::string) SHORT_OPTION_PREFIX))
        {
            ParseShortOption(token);
            return;
        }

        ParseArgument(token);
    });
}

void ArgvInput::ParseArgument(const std::string &token)
{
    int countIndex = m_arguments.size();

    if (m_inputDefinition->HasArgument(countIndex))
    {
        auto arg = m_inputDefinition->GetArgument(countIndex);
        m_arguments[arg.GetName()] = token;
        return;
    }

    throw std::runtime_error("Unknown argument " + token);
}

void ArgvInput::ParseLongOption(const std::string &token)
{
    auto parts = Strings::Split(token.substr(2, token.size() - 2), (std::string) KEY_VALUE_SEPARATOR);

    if (parts.size() != 1)
    {
        AddLongOption(parts[0], parts[1]);
        return;
    }

    AddLongOption(parts[0]);
}

void ArgvInput::ParseShortOption(const std::string &token)
{
    std::cout << "Parsing short option" << std::endl;
}

void ArgvInput::AddLongOption(const std::string &name, const std::optional<std::string> &value)
{
        if (!m_inputDefinition->HasOption(name))
    {
        throw std::runtime_error(Strings::Concatenator() << "No option " << name << " exists");
    }

    auto option = m_inputDefinition->GetOption(name);

    if (value != std::nullopt  && !option.IsAcceptValue())
    {
        throw std::runtime_error(Strings::Concatenator() << "The option " << name << " does not accept value");
    }

    if (value == std::nullopt)
    {
        if (option.IsValueRequired())
        {
            throw std::runtime_error("No value provided for option: " + name);
        }
    }

    auto searchIterator = m_options.find(name);

    if (searchIterator != m_options.end() && !option.IsMultiple())
    {
        searchIterator->second = value;

        return;
    }

    m_options.insert(std::pair(name, value));
}

