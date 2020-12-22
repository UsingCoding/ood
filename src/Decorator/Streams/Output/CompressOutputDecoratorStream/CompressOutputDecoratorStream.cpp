#include "CompressOutputDecoratorStream.hpp"


void CompressOutputDecoratorStream::WriteByte(uint8_t data)
{
    if (m_chunk.IsEmpty())
    {
        m_chunk = { 1, data };
        return;
    }
    if (m_chunk.byte == data && m_chunk.countOfBytes < std::numeric_limits<uint8_t>::max())
    {
        m_chunk.countOfBytes++;
        return;
    }
    Flush();
    m_chunk = { 1, data };
}

void CompressOutputDecoratorStream::WriteBlock(const void *srcData, std::streamsize size)
{
    auto data = static_cast<const uint8_t*>(srcData);
    for (std::streamsize i = 0; i < size; i++)
    {
        WriteByte(*data);
        data++;
    }
}

void CompressOutputDecoratorStream::Flush()
{
    uint8_t chunk[] = {m_chunk.countOfBytes, m_chunk.byte };
    m_stream->WriteBlock(chunk, 2);
    m_chunk.Reset();
}

