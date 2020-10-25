#pragma once

#include "ICompressStreamDecoratorFactory.hpp"

class CompressStreamDecoratorFactory : public ICompressStreamDecoratorFactory
{
public:
    IOutputDataStream::OutputDataStreamPtr DecorateCompressStream(IOutputDataStream::OutputDataStreamPtr stream) override;
    IInputDataStream::InputDataStreamPtr DecorateDecompressStream(IInputDataStream::InputDataStreamPtr stream) override;
};
