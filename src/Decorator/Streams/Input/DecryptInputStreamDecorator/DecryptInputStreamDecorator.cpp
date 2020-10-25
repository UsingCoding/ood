#include "DecryptInputStreamDecorator.hpp"


bool DecryptInputStreamDecorator::IsEOF() const
{
    return m_stream->IsEOF();
}

uint8_t DecryptInputStreamDecorator::ReadByte()
{
    auto byte = m_stream->ReadByte();

    return m_decoder.Decode(byte, m_key);
}

std::streamsize DecryptInputStreamDecorator::ReadBlock(void *dstBuffer, std::streamsize size)
{
    return 0;
}