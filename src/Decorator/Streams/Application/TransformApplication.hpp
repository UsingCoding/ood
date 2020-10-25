#pragma once

#include <memory>
#include <functional>
#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"
#include "../Factory/CryptStreamDecoratorFactory/ICryptStreamDecoratorFactory.hpp"
#include "../Factory/StreamFactory/IStreamFactory.hpp"
#include "../Factory/CompressStreamDecoratorFactory/ICompressStreamDecoratorFactory.hpp"

class TransformApplication
{
public:
    TransformApplication(
        std::unique_ptr<IStreamFactory> streamFactory,
        std::unique_ptr<ICryptStreamDecoratorFactory> cryptStreamDecoratorFactory,
        std::unique_ptr<ICompressStreamDecoratorFactory> compressStreamDecoratorFactory
    ) :
        m_streamFactory(std::move(streamFactory)),
        m_cryptStreamDecoratorFactory(std::move(cryptStreamDecoratorFactory)),
        m_compressStreamDecoratorFactory(std::move(compressStreamDecoratorFactory))
        {}

    void run(std::istream & istream, std::ostream & ostream);
private:
    std::unique_ptr<IStreamFactory> m_streamFactory;
    std::unique_ptr<ICryptStreamDecoratorFactory> m_cryptStreamDecoratorFactory;
    std::unique_ptr<ICompressStreamDecoratorFactory> m_compressStreamDecoratorFactory;
};
