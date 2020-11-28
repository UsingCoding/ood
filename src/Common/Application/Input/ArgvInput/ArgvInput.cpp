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

    if (m_inputDefinition->GetArgumentsCount() != 0)
    {
        auto & arg = m_inputDefinition->GetLastArgument();

        if (arg.GetValueMode() == InputArgument::ValueMode::TEXT)
        {
            auto it = m_arguments.find(arg.GetName());
            it->second = it->second.value() + ' ' + token;

            return;
        }
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
    auto shortcutAndValue = token.substr(1, token.size() - 1);

    if (shortcutAndValue.length() > 1)
    {
        if (m_inputDefinition->HasShortcut(shortcutAndValue[0]) && m_inputDefinition->GetOptionForShortcut(shortcutAndValue[0]).IsAcceptValue())
        {
            auto parts = Strings::Split(shortcutAndValue, (std::string) KEY_VALUE_SEPARATOR);

            if (parts.size() == 1)
            {
                throw std::runtime_error(Strings::Concatenator() << "No value provided for shortcut " << shortcutAndValue[0]);
            }

            AddShortOption(parts[0][0], parts[1]);
        }
        else
        {
            ParseShortOptionList(shortcutAndValue);
        }
    }
    else
    {
        AddShortOption(shortcutAndValue[0]);
    }
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
    m_optionsOrder.push_back(Strings::Concatenator() << name << "=" << value.value_or(""));
}

void ArgvInput::AddShortOption(char shortcut, const std::optional<std::string> &value)
{
    AddLongOption(m_inputDefinition->GetOptionForShortcut(shortcut).GetName(), value);
}

void ArgvInput::ParseShortOptionList(const std::string &token)
{
    std::for_each(token.begin(), token.end(), [&](char symbol){
        if (!m_inputDefinition->HasShortcut(symbol))
        {
            throw std::invalid_argument(Strings::Concatenator() << "No option for shortcut " << symbol <<" found");
        }

        auto option = m_inputDefinition->GetOptionForShortcut(symbol);

        if (option.IsValueRequired())
        {
            throw std::runtime_error(Strings::Concatenator() << "You cannot put in shortcut list option with required value");
        }

        AddLongOption(option.GetName());
    });
}

