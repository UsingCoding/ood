#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../IOutputDataStream.hpp"

class CryptOutputDecoratorStream : public IOutputDataStream
{
public:
    CryptOutputDecoratorStream(IOutputDataStream &mStream, int key) : m_stream(mStream), m_key(key) {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    IOutputDataStream & m_stream;
    int m_key;
};
