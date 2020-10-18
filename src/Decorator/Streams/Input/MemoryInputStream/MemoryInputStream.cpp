#include <algorithm>
#include "MemoryInputStream.hpp"

MemoryInputStream::MemoryInputStream(MemoryInputStream::BufferType && buffer) : m_buffer(std::move(buffer))
{
    std::reverse(m_buffer->begin(), m_buffer->end());
}

bool MemoryInputStream::IsEOF() const
{
    return m_buffer->size() == 0;
}

uint8_t MemoryInputStream::ReadByte()
{
    auto data = m_buffer->at(m_buffer->size() - 1);

    m_buffer->pop_back();

    return data;
}

std::streamsize MemoryInputStream::ReadBlock(void *dstBuffer, std::streamsize size)
{
    return 0;
}
