#include "DecryptInputStreamDecorator.hpp"


bool DecryptInputStreamDecorator::IsEOF() const
{
    return m_stream->IsEOF();
}

uint8_t DecryptInputStreamDecorator::ReadByte()
{
    return 0;
}

std::streamsize DecryptInputStreamDecorator::ReadBlock(void *dstBuffer, std::streamsize size)
{
    return 0;
}