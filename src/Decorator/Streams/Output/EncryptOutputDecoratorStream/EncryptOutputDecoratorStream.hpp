#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../IOutputDataStream.hpp"
#include "../../Crypt/IEncoder.hpp"

class EncryptOutputDecoratorStream : public IOutputDataStream
{
public:
    EncryptOutputDecoratorStream(OutputDataStreamPtr stream, int key, const IEncoder & encoder)
            : m_stream(std::move(stream)), m_key(key), m_encoder(encoder) {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    OutputDataStreamPtr m_stream;
    int m_key;
    const IEncoder & m_encoder;
};
