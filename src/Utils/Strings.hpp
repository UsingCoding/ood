#pragma once

#include <sstream>
#include <vector>

namespace Strings
{
    class Concatenator
    {
    private:
        std::stringstream stream;
    public:
        template<class T>
        Concatenator& operator<< (const T& arg)
        {
            stream << arg;
            return *this;
        }

        operator std::string() const
        {
            return stream.str();
        }
    };

    bool StartsWith(const std::string & value, const std::string & beginOfString);

    std::string Trim(const std::string & value);

    std::vector<std::string> Split(const std::string & value, const std::string & separator);
}