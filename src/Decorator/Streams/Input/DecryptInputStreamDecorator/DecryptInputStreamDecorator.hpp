#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../IInputDataStream.hpp"
#include "../../Crypt/IDecoder.hpp"

class DecryptInputStreamDecorator : public IInputDataStream
{
public:
    DecryptInputStreamDecorator(InputDataStreamPtr stream, int key, const IDecoder &decoder)
            : m_stream(std::move(stream)), m_key(key), m_decoder(decoder) {}

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    InputDataStreamPtr m_stream;
    int m_key;
    const IDecoder & m_decoder;
};
