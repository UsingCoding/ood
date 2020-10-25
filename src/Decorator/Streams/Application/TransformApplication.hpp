#pragma once

#include <memory>
#include <functional>
#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"
#include "../Factory/CryptStreamDecoratorFactory/ICryptStreamDecoratorFactory.hpp"
#include "../Factory/StreamFactory/IStreamFactory.hpp"

class TransformApplication
{
public:
    TransformApplication(
        std::unique_ptr<IStreamFactory> streamFactory,
        std::unique_ptr<ICryptStreamDecoratorFactory> cryptStreamDecoratorFactory
    ) :
        m_streamFactory(std::move(streamFactory)),
        m_cryptStreamDecoratorFactory(std::move(cryptStreamDecoratorFactory))
        {}

    void run(std::istream & istream, std::ostream & ostream);
private:
    std::unique_ptr<IStreamFactory> m_streamFactory;
    std::unique_ptr<ICryptStreamDecoratorFactory> m_cryptStreamDecoratorFactory;
};
