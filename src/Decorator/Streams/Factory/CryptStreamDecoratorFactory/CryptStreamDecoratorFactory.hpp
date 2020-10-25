#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../../Input/IInputDataStream.hpp"
#include "../../Crypt/IEncoder.hpp"
#include "../../Crypt/Encoder.hpp"
#include "ICryptStreamDecoratorFactory.hpp"

class CryptStreamDecoratorFactory : public ICryptStreamDecoratorFactory
{
public:
    CryptStreamDecoratorFactory(const Encoder & encoder) : m_encoder(encoder) {}

    IOutputDataStream::OutputDataStreamPtr DecorateEncryptStream(IOutputDataStream::OutputDataStreamPtr stream, int key);
    IInputDataStream::InputDataStreamPtr DecorateDecryptStream(IInputDataStream::InputDataStreamPtr stream, int key);

private:
    const Encoder & m_encoder;
};
