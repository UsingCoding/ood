#pragma once

#include <vector>
#include <memory>
#include "../IOutputDataStream.hpp"

class MemoryOutputStream : public IOutputDataStream
{
public:
    MemoryOutputStream()
    {
        m_buffer = std::make_unique<std::vector<uint8_t>>();
    }

    typedef std::unique_ptr<std::vector<uint8_t>> BufferType;

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

    BufferType && GetBuffer();

private:
    BufferType m_buffer;
};
