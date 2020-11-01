#pragma once

#include <iosfwd>

namespace Common::Console
{
    class IOutput
    {
    public:
        virtual std::ostream & operator*() = 0;
    };
}
