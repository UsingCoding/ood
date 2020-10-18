#pragma once

#include <vector>
#include <memory>
#include "../IInputDataStream.hpp"

class MemoryInputStream : public IInputDataStream
{
public:
    typedef std::unique_ptr<std::vector<uint8_t>> BufferType;

    MemoryInputStream(BufferType && buffer);

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    BufferType m_buffer;
};