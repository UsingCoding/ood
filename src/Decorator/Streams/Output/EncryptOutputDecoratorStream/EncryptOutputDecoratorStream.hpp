#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../IOutputDataStream.hpp"

class EncryptOutputDecoratorStream : public IOutputDataStream
{
public:
    EncryptOutputDecoratorStream(OutputDataStreamPtr stream, int key) : m_stream(std::move(stream)), m_key(key) {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    OutputDataStreamPtr m_stream;
    int m_key;
};
