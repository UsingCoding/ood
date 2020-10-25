#include "Strings.hpp"

bool Strings::StartsWith(const std::string & value, const std::string & beginOfString)
{
    if (value.length() < beginOfString.length())
    {
        return false;
    }

    return value.substr(0, beginOfString.length()) == beginOfString;
}

std::string Strings::Trim(const std::string & value)
{
    const std::string chars = "\t\n\v\f\r ";
    std::string cpValue = value;

    cpValue.erase(0, cpValue.find_first_not_of(chars));
    cpValue.erase(cpValue.find_last_not_of(chars) + 1);
    return cpValue;
}
