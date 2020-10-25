#include "CryptStreamDecoratorFactory.hpp"
#include "../../Output/EncryptOutputDecoratorStream/EncryptOutputDecoratorStream.hpp"
#include "../../Input/DecryptInputStreamDecorator/DecryptInputStreamDecorator.hpp"

IOutputDataStream::OutputDataStreamPtr CryptStreamDecoratorFactory::DecorateEncryptStream(IOutputDataStream::OutputDataStreamPtr stream, int key)
{
    return std::make_unique<EncryptOutputDecoratorStream>(std::move(stream), key, m_encoder);
}

IInputDataStream::InputDataStreamPtr CryptStreamDecoratorFactory::DecorateDecryptStream(IInputDataStream::InputDataStreamPtr stream, int key)
{
    return std::make_unique<DecryptInputStreamDecorator>(std::move(stream), key, m_encoder);
}


