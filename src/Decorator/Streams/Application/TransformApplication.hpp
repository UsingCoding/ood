#pragma once

#include <memory>
#include <functional>
#include <vector>
#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"
#include "../Factory/CryptStreamDecoratorFactory/ICryptStreamDecoratorFactory.hpp"
#include "../Factory/StreamFactory/IStreamFactory.hpp"
#include "../Factory/CompressStreamDecoratorFactory/ICompressStreamDecoratorFactory.hpp"
#include "Input/InputDefinition/InputDefinition.hpp"

class TransformApplication
{
public:
    typedef std::unique_ptr<std::vector<std::string>> InputArgs;

    TransformApplication(
        std::unique_ptr<IStreamFactory> streamFactory,
        std::unique_ptr<ICryptStreamDecoratorFactory> cryptStreamDecoratorFactory,
        std::unique_ptr<ICompressStreamDecoratorFactory> compressStreamDecoratorFactory
    ) :
        m_streamFactory(std::move(streamFactory)),
        m_cryptStreamDecoratorFactory(std::move(cryptStreamDecoratorFactory)),
        m_compressStreamDecoratorFactory(std::move(compressStreamDecoratorFactory))
        {}

    void Run(const InputArgs & inputArgs);
private:
    std::unique_ptr<IStreamFactory> m_streamFactory;
    std::unique_ptr<ICryptStreamDecoratorFactory> m_cryptStreamDecoratorFactory;
    std::unique_ptr<ICompressStreamDecoratorFactory> m_compressStreamDecoratorFactory;

    void DoRun(std::unique_ptr<InputDefinition> inputDefinition);
    std::unique_ptr<InputDefinition> BuildInputDefinition(const InputArgs & inputArgs);
};
