#include "CompressStreamDecoratorFactory.hpp"
#include "../../Output/CompressOutputDecoratorStream/CompressOutputDecoratorStream.hpp"
#include "../../Input/DecompressInputStreamDecorator/DecompressInputStreamDecorator.hpp"

IOutputDataStream::OutputDataStreamPtr CompressStreamDecoratorFactory::DecorateCompressStream(IOutputDataStream::OutputDataStreamPtr stream)
{
    return std::make_unique<CompressOutputDecoratorStream>(std::move(stream));
}

IInputDataStream::InputDataStreamPtr CompressStreamDecoratorFactory::DecorateDecompressStream(IInputDataStream::InputDataStreamPtr stream)
{
    return std::make_unique<DecompressInputStreamDecorator>(std::move(stream));
}
