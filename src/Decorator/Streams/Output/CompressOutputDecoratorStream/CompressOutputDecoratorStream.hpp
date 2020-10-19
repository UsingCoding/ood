#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../IOutputDataStream.hpp"

class CompressOutputDecoratorStream : public IOutputDataStream
{
public:
    CompressOutputDecoratorStream(OutputDataStreamPtr stream) : m_stream(std::move(stream)) {}

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    OutputDataStreamPtr m_stream;
};
