#pragma once

#include <iosfwd>

class StreamBufferOverrider
{
public:
    StreamBufferOverrider(
        std::ostream &streamToOverride,
        std::ostream &overrideStream
    );

    ~StreamBufferOverrider();

private:
    std::ostream & m_streamToOverride;
    std::ostream & m_overrideStream;
    std::streambuf * m_overridedStreamBuffer;
};
