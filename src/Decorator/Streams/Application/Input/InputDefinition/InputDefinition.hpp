#pragma once

#include <map>
#include <optional>
#include <vector>
#include <memory>
#include <list>

class InputDefinition
{
public:
    typedef std::list<std::pair<std::string, std::optional<std::string>>> OptionalArgumentsContainer;
    typedef std::vector<std::string> PositionalArgumentsContainer;

    InputDefinition():
        m_optionalArguments(std::make_unique<OptionalArgumentsContainer>()),
        m_positionalArguments(std::make_unique<PositionalArgumentsContainer>())
    {}

    void AddOptionalArgument(const std::string & key, const std::optional<std::string> & value);
    void AddPositionalArgument(const std::string & value);

    size_t  GetOptionalArgumentsCount() const;
    size_t  GetPositionalArgumentsCount() const;

    std::string GetPositionalArgument(size_t index) const;

    void DoForEachOptionalArgument(std::function<void(const OptionalArgumentsContainer::value_type &)>) const;

private:
    std::unique_ptr<OptionalArgumentsContainer> m_optionalArguments;
    std::unique_ptr<PositionalArgumentsContainer> m_positionalArguments;
};
