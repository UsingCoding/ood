#pragma once

#include <vector>
#include <memory>
#include "../IOutputDataStream.hpp"

class MemoryOutputStream : public IOutputDataStream
{
public:
    typedef std::vector<uint8_t> BufferType;

    MemoryOutputStream(BufferType & buffer): m_buffer(buffer)
    {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    BufferType & m_buffer;
};
