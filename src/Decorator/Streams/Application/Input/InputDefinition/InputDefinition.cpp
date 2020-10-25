#include <Strings.hpp>
#include <functional>
#include "InputDefinition.hpp"

void InputDefinition::AddOptionalArgument(const std::string &key, const std::optional<std::string> &value)
{
    m_optionalArguments->push_back(std::make_pair(key, value));
}

void InputDefinition::AddPositionalArgument(const std::string &value)
{
    m_positionalArguments->push_back(value);
}

size_t  InputDefinition::GetOptionalArgumentsCount() const
{
    return m_optionalArguments->size();
}

size_t  InputDefinition::GetPositionalArgumentsCount() const
{
    return m_positionalArguments->size();
}


std::string InputDefinition::GetPositionalArgument(size_t index) const
{
    auto it = m_optionalArguments->begin();

    if (index >= m_positionalArguments->size())
    {
        throw std::logic_error(Strings::Concatenator() << "Accessing positional argument after size, index: " << index);
    }

    return (*m_positionalArguments)[index];
}

void InputDefinition::DoForEachOptionalArgument(std::function<void(const InputDefinition::OptionalArgumentsContainer::value_type &)> callback) const
{
    std::for_each(m_optionalArguments->begin(), m_optionalArguments->end(), callback);
}

