#include "DecompressInputStreamDecorator.hpp"

bool DecompressInputStreamDecorator::IsEOF() const
{
    return m_stream->IsEOF();
}

uint8_t DecompressInputStreamDecorator::ReadByte()
{
    if (m_chunk.IsEmpty())
    {
        m_chunk.countOfBytes = m_stream->ReadByte();
        m_chunk.byte = m_stream->ReadByte();
    }

    m_chunk.countOfBytes--;

    return m_chunk.byte;
}

std::streamsize DecompressInputStreamDecorator::ReadBlock(void *dstBuffer, std::streamsize size)
{
    auto data = static_cast<uint8_t*>(dstBuffer);

    for (std::streamsize i = 0; i < size; i++)
    {
        try
        {
            *data = ReadByte();
        }
        catch (std::exception&)
        {
            return i + 1;
        }
        data++;
    }

    return size;
}
