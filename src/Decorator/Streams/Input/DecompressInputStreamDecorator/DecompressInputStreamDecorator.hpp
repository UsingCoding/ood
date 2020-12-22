#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../IInputDataStream.hpp"
#include "../../Chunk/Chunk.hpp"

class DecompressInputStreamDecorator : public IInputDataStream
{
public:
    DecompressInputStreamDecorator(InputDataStreamPtr stream) : m_stream(std::move(stream)) {}

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    InputDataStreamPtr m_stream;

    Chunk m_chunk;
};
