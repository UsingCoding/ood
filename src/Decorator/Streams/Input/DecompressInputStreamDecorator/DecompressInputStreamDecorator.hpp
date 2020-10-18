#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../IInputDataStream.hpp"

class DecompressInputStreamDecorator : public IInputDataStream
{
public:
    DecompressInputStreamDecorator(IInputDataStream &stream) : m_stream(stream) {}

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    IInputDataStream & m_stream;
};
