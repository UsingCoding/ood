#pragma once

#include <sstream>

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
}