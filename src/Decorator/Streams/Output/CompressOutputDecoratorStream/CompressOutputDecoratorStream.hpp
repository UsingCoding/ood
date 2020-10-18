#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../IOutputDataStream.hpp"

class CompressOutputDecoratorStream : public IOutputDataStream
{
public:
    CompressOutputDecoratorStream(IOutputDataStream &mStream) : m_stream(mStream) {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    IOutputDataStream & m_stream;
};
