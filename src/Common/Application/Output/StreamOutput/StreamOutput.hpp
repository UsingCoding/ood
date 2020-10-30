#pragma once

#include <Application/Output/IOutput.hpp>
#include <iosfwd>

namespace Common::Console
{
    class StreamOutput : public IOutput
    {
    public:
        StreamOutput(std::ostream &ostream);

    private:
        std::ostream & m_ostream;
    };
}
