#include "MemoryOutputStream.hpp"

void MemoryOutputStream::WriteByte(uint8_t data)
{
    m_buffer->push_back(data);
}

void MemoryOutputStream::WriteBlock(const void *srcData, std::streamsize size)
{
    auto buffer = static_cast<const uint8_t*>(srcData);
    for (std::streamsize i = 0; i < size; i++)
    {
        WriteByte(*buffer);
        buffer++;
    }
}
