#include "MemoryOutputStream.hpp"

void MemoryOutputStream::WriteByte(uint8_t data)
{
    m_buffer.push_back(data);
}

void MemoryOutputStream::WriteBlock(const void *srcData, std::streamsize size)
{

}
