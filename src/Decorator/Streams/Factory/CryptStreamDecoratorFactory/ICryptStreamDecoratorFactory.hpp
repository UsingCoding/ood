#pragma once

#include "../../Output/IOutputDataStream.hpp"
#include "../../Input/IInputDataStream.hpp"

class ICryptStreamDecoratorFactory
{
public:
    virtual IOutputDataStream::OutputDataStreamPtr DecorateEncryptStream(IOutputDataStream::OutputDataStreamPtr stream, int key) = 0;
    virtual IInputDataStream::InputDataStreamPtr DecorateDecryptStream(IInputDataStream::InputDataStreamPtr stream, int key) = 0;
};
