#include "DecompressInputStreamDecorator.hpp"

bool DecompressInputStreamDecorator::IsEOF() const
{
    return m_stream->IsEOF();
}

uint8_t DecompressInputStreamDecorator::ReadByte()
{
    return 0;
}

std::streamsize DecompressInputStreamDecorator::ReadBlock(void *dstBuffer, std::streamsize size)
{
    return 0;
}
