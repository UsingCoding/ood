#pragma once

#include "../../Input/IInputDataStream.hpp"
#include "../../Output/IOutputDataStream.hpp"

class ICompressStreamDecoratorFactory
{
public:
    virtual IOutputDataStream::OutputDataStreamPtr DecorateCompressStream(IOutputDataStream::OutputDataStreamPtr stream) = 0;
    virtual IInputDataStream::InputDataStreamPtr DecorateDecompressStream(IInputDataStream::InputDataStreamPtr stream) = 0;
};