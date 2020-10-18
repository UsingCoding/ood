#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../IInputDataStream.hpp"

class DecryptInputStreamDecorator : public IInputDataStream
{
public:
    DecryptInputStreamDecorator(IInputDataStream &stream, int key) : m_stream(stream), m_key(key) {}

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    IInputDataStream & m_stream;
    int m_key;
};
