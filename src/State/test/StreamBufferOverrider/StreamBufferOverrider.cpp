#include <iostream>
#include "StreamBufferOverrider.hpp"


StreamBufferOverrider::StreamBufferOverrider(
        std::ostream &streamToOverride,
        std::ostream &overrideStream)
: m_streamToOverride(streamToOverride), m_overrideStream(overrideStream)
{
    m_overridedStreamBuffer = m_streamToOverride.rdbuf();

    m_streamToOverride.rdbuf(overrideStream.rdbuf());
}

StreamBufferOverrider::~StreamBufferOverrider()
{
    m_streamToOverride.rdbuf(m_overridedStreamBuffer);
}
